#include<iostream>
#include<vector>
#include<algorithm>	// for min, max, sort
#include<cmath>		// for atan2
#include<fstream>	// for ifstream (file access)

using namespace std;

/*
*  
* 각도의 범위와 관련된 구조체와 함수 정의
* 
*/
const double pi = 3.14159265358979323846;	// 원주율 상수 정의

struct AnglePair 
{
	double from, to;
	AnglePair(double from, double to) 
	{
		this->from = from;
		this->to = to;
	}
};

bool intersect(AnglePair r1, AnglePair r2) 
{
	double fromMax = max(r1.from, r2.from);
	double toMin = min(r1.to, r2.to);
	return fromMax < toMin;
}

bool intersectList(vector<AnglePair> list1, vector<AnglePair> list2) 
{
	for (unsigned int i = 0; i < list1.size(); i++) 
	{
		for (unsigned int j = 0; j < list2.size(); j++) 
		{
			if (intersect(list1[i], list2[j])) return true;
		}
	}
	return false;
}

AnglePair merge(AnglePair r1, AnglePair r2) 
{
	double fromMin = min(r1.from, r2.from);
	double toMax = max(r1.to, r2.to);
	return AnglePair(fromMin, toMax);
}

/*
* AnglePair의 리스트에 대한 정렬 기준을 정하는 함수
* r1이 r2보다 작을 때 true를 return하도록 함
*/
bool compareAnglePairs(AnglePair r1, AnglePair r2) 
{
	if (r1.from < r2.from) return true;
	else if (r1.from > r2.from) return false;
	else 
	{
		if (r1.to < r2.to) return true;
		else return false;
	}
}

vector<AnglePair> mergeList(vector<AnglePair> list1, vector<AnglePair> list2) {
	vector<AnglePair> all;
	all.insert(all.end(), list1.begin(), list1.end());	// add all elements of list1
	all.insert(all.end(), list2.begin(), list2.end());	// add all elements of list2
	sort(all.begin(), all.end(), compareAnglePairs);

	vector<AnglePair> merged;
	AnglePair prev = all[0];
	for (unsigned int i = 1; i < all.size(); i++) 
	{
		AnglePair next = all[i];
		if (intersect(prev, next)) 
		{
			prev = merge(prev, next);
		}
		else 
		{
			merged.push_back(prev);
			prev = next;
		}
	}
	merged.push_back(prev);

	return merged;
}

/*
* p0와 p1이 이루는 각도 및 p0와 p2가 이루는 각도를 AnglePair로 만들어 반환
* 두 각도의 차이가 pi(180도) 이상이라면 2개의 range로 나누어 반환
*/
vector<AnglePair> createAnglePairList(double p0x, double p0y, double p1x, double p1y, double p2x, double p2y) 
{
	double angle1 = atan2(p1y - p0y, p1x - p0x);
	double angle2 = atan2(p2y - p0y, p2x - p0x);
	double angleMin = min(angle1, angle2);
	double angleMax = max(angle1, angle2);

	vector<AnglePair> list;
	if (angleMax - angleMin < pi) 
	{
		list.push_back(AnglePair(angleMin, angleMax));
	}
	else 
	{
		list.push_back(AnglePair(angleMax, pi));
		list.push_back(AnglePair(-pi, angleMin));
	}

	return list;
}


/*
*
* 지도와 관련된 구조체와 함수 정의
*
*/
const double cellLength = 1.0;	// 각 cell의 가로세로 길이. 각 cell의 4개 포인트의 xy좌표 계산에 사용

struct Map
{
	int N;					// (s,t) = (1,1) ~ (N,N) 까지의 NxN개 cell을 갖는 map
	int sPlayer, tPlayer;	// player의 s(가로)와 t(세로) 좌표	
	vector<vector<bool>> obstacleMap;	// N+1 by N+1 배열. map의 cell[t][s]에 대해 true이면 장애물 있고 false이면 장애물 없음	
	vector<vector<int>> shade;	// N+1 by N+1 배열. map의 cell[t][s]에 대한 그림자 정도 (0: 그림자 없음, 1: 그림자 있음)
	double d1, d2;				// 사용자가 보는 각도 d1~d2까지 (d1 != d2)

	// 생성자 함수: 인자에서 지정한 경로에서 파일 읽어 구조체 초기화
	Map(string filePath)
	{
		ifstream file(filePath);	// 절대 경로 사용 예: ifstream file("c:/test1.txt"); // 정방향 / 아닌 역방향 \ 사용하는 경우에는 2개(\\) 사용해야 함에 유의
		file >> N;					// read N from file		

		obstacleMap.insert(obstacleMap.begin(), N + 1, vector<bool>(N + 1, false));	// N+1 by N+1 크기 배열로 초기화 (초깃값은 false)
		string line;
		for (int t = N; t >= 1; t--)
		{
			file >> line;
			for (int s = 1; s <= N; s++)
			{
				obstacleMap[t][s] = line[s - 1] == '0' ? false : true;	// no obstacle vs. obstacle				
			}
		}		
		file >> sPlayer >> tPlayer;
		file >> d1 >> d2;
		file.close();

		shade.insert(shade.begin(), N + 1, vector<int>(N + 1, 0));	// N+1 by N+1 크기 배열로 초기화 (초깃값은 0)
	}
};

void setPlayerPosition(Map &map, int sPlayer, int tPlayer)
{
	map.sPlayer = sPlayer; map.tPlayer = tPlayer;
}

// 장애물 map 출력
void printMap(Map &map)
{
	for (int t = map.N; t >= 1; t-- )
	{
		for(int s=1;s<=map.N;s++)
		{ 
			cout << map.obstacleMap[t][s] ? "1" : "0";
		}
		cout << endl;
	}
	cout << endl;
}

// shade에 지정된 음영 출력
void printShade(Map &map)
{
	for (int t = map.N; t >= 1; t--)
	{
		for (int s = 1; s <= map.N; s++)
		{
			if (t == map.tPlayer && s == map.sPlayer) cout << "P";
			else if (map.obstacleMap[t][s]) cout << "1";
			else cout << (map.shade[t][s]>0 ? "x" : "o");
		}
		cout << endl;
	}
	cout << endl;
}

/*
 * 검사 대상인 cell에 대해 (sCell, tCell은 각각 이 cell의 가로좌표와 세로좌표)
 * player로부터의 각도 범위를 계산하기 위한 2개 점의 s, t좌표를 계산하여
 * 이들을 double[] 배열에 차례로 넣어 반환 
 */
vector<double> getXYCoordinatesOfCell(Map &map, double sCell, double tCell) 
{
	vector<double> xyCoordinates(4, 0);

	if (map.tPlayer < tCell)
	{
		if (map.sPlayer > sCell)
		{
			xyCoordinates[0] = (sCell - 1) * cellLength; xyCoordinates[1] = (tCell - 1) * cellLength;
			xyCoordinates[2] = sCell * cellLength; xyCoordinates[3] = tCell * cellLength;
		}
		else if (map.sPlayer == sCell)
		{
			xyCoordinates[0] = (sCell - 1) * cellLength; xyCoordinates[1] = (tCell - 1) * cellLength;
			xyCoordinates[2] = sCell * cellLength; xyCoordinates[3] = (tCell - 1) * cellLength;
		}
		else if (map.sPlayer < sCell)
		{
			xyCoordinates[0] = (sCell - 1) * cellLength; xyCoordinates[1] = tCell * cellLength;
			xyCoordinates[2] = sCell * cellLength; xyCoordinates[3] = (tCell - 1) * cellLength;
		}
	}
	else if (map.tPlayer == tCell)
	{
		if (map.sPlayer > sCell)
		{
			xyCoordinates[0] = sCell * cellLength; xyCoordinates[1] = tCell * cellLength;
			xyCoordinates[2] = sCell * cellLength; xyCoordinates[3] = (tCell - 1) * cellLength;
		}
		else if (map.sPlayer == sCell)
		{
			// this case does NOT happen
		}
		else if (map.sPlayer < sCell)
		{
			xyCoordinates[0] = (sCell - 1) * cellLength; xyCoordinates[1] = tCell * cellLength;
			xyCoordinates[2] = (sCell - 1) * cellLength; xyCoordinates[3] = (tCell - 1) * cellLength;
		}
	}
	else if (map.tPlayer > tCell)
	{
		if (map.sPlayer > sCell)
		{
			xyCoordinates[0] = (sCell - 1) * cellLength; xyCoordinates[1] = tCell * cellLength;
			xyCoordinates[2] = sCell * cellLength; xyCoordinates[3] = (tCell - 1) * cellLength;
		}
		else if (map.sPlayer == sCell)
		{
			xyCoordinates[0] = (sCell - 1) * cellLength; xyCoordinates[1] = tCell * cellLength;
			xyCoordinates[2] = sCell * cellLength; xyCoordinates[3] = tCell * cellLength;
		}
		else if (map.sPlayer < sCell)
		{
			xyCoordinates[0] = (sCell - 1) * cellLength; xyCoordinates[1] = (tCell - 1) * cellLength;
			xyCoordinates[2] = sCell * cellLength; xyCoordinates[3] = tCell * cellLength;
		}
	}

	return xyCoordinates;
}

vector<AnglePair> checkCell(Map &map, vector<AnglePair> obstacleList, int s, int t)
{
	if (1 <= s && s <= map.N && 1 <= t && t <= map.N)
	{
		// 사용자의 중심(사용자가 위치한 격자의 중심)의 xy 좌표 계산. 각도 계산 위함
		double p0x = map.sPlayer * cellLength - cellLength / 2.0;
		double p0y = map.tPlayer * cellLength - cellLength / 2.0;

		if (map.obstacleMap[t][s])
		{
			// 장애물이 있는 경우
			vector<double> xyCoordinates = getXYCoordinatesOfCell(map, s, t);
			vector<AnglePair> apList = createAnglePairList(p0x, p0y,
				xyCoordinates[0], xyCoordinates[1], xyCoordinates[2], xyCoordinates[3]);
			obstacleList = mergeList(obstacleList, apList);	// 기존 장애물 리스트에 각도 추가
			map.shade[t][s] = 1;	// 음영처리
		}
		else
		{
			// 장애물이 없는 경우
			vector<double> xyCoordinates = getXYCoordinatesOfCell(map, s, t);
			vector<AnglePair> apList = createAnglePairList(p0x, p0y,
				xyCoordinates[0], xyCoordinates[1], xyCoordinates[2], xyCoordinates[3]);
			if (intersectList(apList, obstacleList)) // 기존 장애물 각도와 겹칠 때 음영처리 
				map.shade[t][s] = 1;
		}
	}

	return obstacleList;
}

/*
 * player의 현재 위치를 기준으로 그림자가 있는 cell 다시 계산
 * player의 위치가 바뀌면 다시 호출할 것
 */
void createShade(Map &map)
{
	// shade 리셋
	map.shade.clear();
	map.shade.insert(map.shade.begin(), map.N + 1, vector<int>(map.N + 1, 0));

	vector<AnglePair> obstacleList;	// player 현재 위치 기준으로 장애물이 있는 각도 범위의 목록 

	obstacleList.push_back(AnglePair(map.d2*pi/180,map.d1*pi/180));

	// player의 현재 위치로부터 최대로 얼마나 멀리 떨어진 거리까지 정사각형을 그리며 조사해야 하는지 결정
	int distanceMax = max(max(max(map.N - map.sPlayer, map.N - map.tPlayer), map.sPlayer - 1), map.tPlayer - 1);

	for (int distance = 1; distance <= distanceMax; distance++)
	{
		int i = 0;
		while (i < distance)
		{
			obstacleList = checkCell(map, obstacleList, map.sPlayer - i, map.tPlayer + distance); // up
			obstacleList = checkCell(map, obstacleList, map.sPlayer + distance, map.tPlayer + i); // right
			obstacleList = checkCell(map, obstacleList, map.sPlayer + i, map.tPlayer - distance); // down
			obstacleList = checkCell(map, obstacleList, map.sPlayer - distance, map.tPlayer - i); // left

			i += 1;
			obstacleList = checkCell(map, obstacleList, map.sPlayer + i, map.tPlayer + distance); // up
			obstacleList = checkCell(map, obstacleList, map.sPlayer + distance, map.tPlayer - i); // right
			obstacleList = checkCell(map, obstacleList, map.sPlayer - i, map.tPlayer - distance); // down
			obstacleList = checkCell(map, obstacleList, map.sPlayer - distance, map.tPlayer + i); // left
		}
	}
}

int main() 
{
	// 장애물 지도와 사용자의 현재 s(가로), t(세로) 좌표 입력받아 Map 객체 생성
	Map map = Map("test1.txt");

	createShade(map);
	printShade(map);

	return 0;
}