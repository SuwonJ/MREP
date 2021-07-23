//승률방식

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;

const int treePlayer = 1, randomPlayer = -1, noPlayer = 0; // tree/random/no player

struct Move {
	int numBlackToTake, numWhiteToTake;
	Move(int numBlackToTake, int numWhiteToTake) {
		this->numBlackToTake = numBlackToTake;
		this->numWhiteToTake = numWhiteToTake;
	}
};

const Move* validMoves[] = { new Move(1,0), new Move(2,0), new Move(0,1), new Move(0,2) };

struct Node {
	int numBlack, numWhite;
	int currentPlayer;
	int numWin = 0, numLoss = 0;	
	Node* parent = NULL;
	vector<Node*> children;
	Move* move = NULL;
	Node(int numBlack, int numWhite, int currentPlayer) {
		this->numBlack = numBlack;
		this->numWhite = numWhite;
		this->currentPlayer = currentPlayer;
	}

	/*
	* decide whether game has terminated
	* if yes, add # of wins/losses to all parents of current node
	*			and return winner
	* if no, return no player
	*/
	int decideWinner() {
		if (numBlack == 0 && numWhite == 0) {
			if (this->currentPlayer == treePlayer) numWin = 1;
			else numLoss = 1;

			Node* currentParent = parent;
			while (currentParent != NULL) {
				currentParent->numWin += this->numWin;
				currentParent->numLoss += this->numLoss;
				currentParent = currentParent->parent;
			}

			return this->currentPlayer;
		}
		else return noPlayer;		
	}

	bool canProceed(Move* move) {
		if (numBlack < move->numBlackToTake) return false;
		if (numWhite < move->numWhiteToTake) return false;
		if (move->numBlackToTake > 0 && move->numWhiteToTake > 0) return false;
		return true;
	}

	bool proceed(Move* move) {
		if (canProceed(move)) {
			numBlack -= move->numBlackToTake;
			numWhite -= move->numWhiteToTake;
			this->move = move;

			if (this->currentPlayer == treePlayer) this->currentPlayer = randomPlayer;
			else if (this->currentPlayer == randomPlayer) this->currentPlayer = treePlayer;

			return true;
		}
		else return false;
	}

	// create a child that clones this node
	Node* clone() {
		Node* node = new Node(this->numBlack, this->numWhite, this->currentPlayer);
		this->children.push_back(node);
		node->parent = this;
		return node;
	}

	string toString() {
		return "(" + to_string(this->numBlack) + "," + to_string(this->numWhite) + ")";
	}

	double winRate() {
		if (this->numWin == 0 && this->numLoss == 0) return 0;
		else return (double) numWin / (numWin + numLoss);
	}

	double lossRate() {
		if (this->numWin == 0 && this->numLoss == 0) return 0;
		else return (double) numLoss / (numWin + numLoss);
	}

	string toStringDFS(int depth = 0) {
		stringstream stream;
		
		for (int i = 0; i < depth; i++) stream << " #";
		stream << this->toString();
		stream << " winRate:" << fixed << setprecision(3) << this->winRate();
		stream << " (" << this->numWin << "/" << (this->numWin + this->numLoss) << ")";
		stream << endl;

		for (int i = 0; i < children.size(); i++) {
			Node* node = children.at(i);
			if (node != NULL)
				stream << node->toStringDFS(depth + 1);
		}

		return stream.str();
	}
};

int currentPlayer;				// player who makes current movement
vector<Node*> nodeList;			// all nodes in game tree
Node* currentNode = NULL;		// node in game tree that corresponds to current state

void createGameTree(int numBlack, int numWhite, int currentPlayer) {
	currentNode = new Node(numBlack, numWhite, currentPlayer);
	nodeList.push_back(currentNode);
	unsigned int index = 0;
	while (index < nodeList.size()) {
		Node* node = nodeList.at(index);
		if (node->decideWinner() == noPlayer) {
			// if node is not a leaf, create children nodes
			for (int i = 0; i < (sizeof(validMoves) / sizeof(*validMoves)); i++) {
				Move* move = (Move*)validMoves[i];
				if (node->canProceed(move)) {
					Node* child = node->clone();
					child->proceed(move);
					nodeList.push_back(child);
				}
			}			
		}
		index++;
	}

	cout << "# of nodes created: " << nodeList.size() << endl;
}

void proceedTreePlayerMove() {
	//cout << currentNode->toStringDFS() << endl;

	// choose a move on game tree with the highest winning rate
	double maxWinRate = 0;
	Node* maxNode = NULL;
	for (int i = 0; i < currentNode->children.size(); i++) {
		Node* node = currentNode->children.at(i);
		if (maxNode == NULL
			|| node->winRate() > maxWinRate) {
			maxNode = node;
			maxWinRate = node->winRate();
		}
	}

	currentNode = maxNode;
}

void proceedRandomPlayerMove() {
	// find moves that are possible on current state
	vector<Move*> possibleMoves;
	for (int i = 0; i < (sizeof(validMoves) / sizeof(*validMoves)); i++) {
		Move* move = (Move*)validMoves[i];
		if (currentNode->canProceed(move)) {
			possibleMoves.push_back(move);
		}
	}

	// randomly choose one move among possible moves
	unsigned int index = rand() % possibleMoves.size();
	Move* move = possibleMoves.at(index);

	// trace down game tree according to selected move
	for (int i = 0; i < currentNode->children.size(); i++) {
		Node* node = currentNode->children.at(i);
		if (node->move == move) {
			currentNode = node;
			break;
		}
	}
}

int main() {
	int numBlack, numWhite;		
	string firstPlayer = "";	// player who makes 1st movement, where 't' and 'r' for tree/random player, respectively
	
	cout << "다음을 입력하세요:" << endl;
	cout << "(1) 검은 돌 수(2) 흰 돌 수(3) 시작 player('t'는 트리 player, 'r'은 random player 의미)" << endl;
	cout << "예: '2 1 t' 입력하면, 검은 돌 2개, 흰 돌 1개, 트리 player를 시작 player로 게임을 진행함 의미" << endl;
	cin >> numBlack >> numWhite >> firstPlayer;	
	
	if (firstPlayer.compare("t") == 0) {
		currentPlayer = treePlayer;
	}
	else if (firstPlayer.compare("r") == 0) {
		currentPlayer = randomPlayer;
	}
	else return 1;

	createGameTree(numBlack, numWhite, currentPlayer);
	//cout << currentNode->toStringDFS() << endl;	

	srand(time(0));	// seed pseudo-random-number generator with current time
	while (true) {
		cout << currentNode->toString();
		if (currentNode->numBlack == 0 && currentNode->numWhite == 0) break;

		if (currentPlayer == treePlayer) {
			cout << ":Tree player" << endl;
			proceedTreePlayerMove();
			currentPlayer = randomPlayer;
		}
		else if (currentPlayer == randomPlayer) {
			cout << ":Random player" << endl;
			proceedRandomPlayerMove();
			currentPlayer = treePlayer;
		}
	}

	if (currentPlayer == treePlayer) cout << ":Tree player won" << endl;
	else if (currentPlayer == randomPlayer) cout << ":Random player won" << endl;

	return 0;
}