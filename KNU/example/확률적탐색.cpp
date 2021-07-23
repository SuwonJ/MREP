//확률적탐색

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
#include<cmath>

using namespace std;

const int treePlayer = 1, randomPlayer = -1, noPlayer = 0; // tree/random/no player
int numSimulations = 1000;

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
	const Move* move = NULL;
	Node(int numBlack, int numWhite, int currentPlayer) {
		this->numBlack = numBlack;
		this->numWhite = numWhite;
		this->currentPlayer = currentPlayer;

		// initialize all children with NULL, until they are selected and created
		for (int i = 0; i < (sizeof(validMoves) / sizeof(*validMoves)); i++) {
			this->children.push_back(NULL);
		}
	}

	/*
	* decide whether game has terminated
	* if yes, remove all children and return winner
	* if no, return no player, meaning no one wins yet
	*/
	int decideWinner() {
		if (numBlack == 0 && numWhite == 0) {
			this->children.clear();
			return this->currentPlayer;
		}
		else return noPlayer;
	}

	bool canProceed(const Move* move) {
		if (numBlack < move->numBlackToTake) return false;
		if (numWhite < move->numWhiteToTake) return false;
		if (move->numBlackToTake > 0 && move->numWhiteToTake > 0) return false;
		return true;
	}

	bool proceed(const Move* move) {
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

	Node* clone() {
		Node* node = new Node(this->numBlack, this->numWhite, this->currentPlayer);
		return node;
	}

	Node* createChild(int index, const Move* move) {
		Node* child = new Node(this->numBlack, this->numWhite, this->currentPlayer);
		child->parent = this;
		this->children[index] = child;
		child->proceed(move);
		return child;
	}

	string toString() {
		return "(" + to_string(this->numBlack) + "," + to_string(this->numWhite) + ")";
	}

	double winRate() {
		if (this->numWin == 0 && this->numLoss == 0) return 0;
		else return (double)numWin / (numWin + numLoss);
	}

	double lossRate() {
		if (this->numWin == 0 && this->numLoss == 0) return 0;
		else return (double)numLoss / (numWin + numLoss);
	}

	int numSimulations() {
		return (numWin + numLoss);
	}

	// compute priority value used for selection step of Monte-Carlo simulation
	const double c = sqrt(2);
	double priority() {
		double winRate = 0;

		if (parent->currentPlayer == treePlayer) winRate = this->winRate();
		else if (parent->currentPlayer == randomPlayer) winRate = this->lossRate();

		return winRate + c * sqrt(log((double)parent->numSimulations())/(double)this->numSimulations());
	}

	// starting from current node, simulate game til it ends
	int simulate() {
		while (this->decideWinner() == noPlayer) {
			// find moves that are possible on current state
			vector<const Move*> possibleMoves;
			for (int i = 0; i < (sizeof(validMoves) / sizeof(*validMoves)); i++) {
				const Move* move = validMoves[i];
				if (this->canProceed(move)) {
					possibleMoves.push_back(move);
				}
			}

			if (possibleMoves.size() == 0) {
				cerr << "no way to proceed" << endl;
				exit(1);
			}

			// randomly choose one move among possible moves
			unsigned int index = rand() % possibleMoves.size();
			this->proceed(possibleMoves.at(index));
		}

		return this->decideWinner();
	}

	// starting from current node, update scores of all nodes on the way to root
	void updateNumbersTowardRoot(int numWin, int numLoss) {
		Node* node = this;
				
		while (node != NULL) {
			node->numWin += numWin;
			node->numLoss += numLoss;
			node = node->parent;
		}
	}

	string toStringDFS(int depth = 0) {
		stringstream stream;

		for (int i = 0; i < depth; i++) stream << " ";
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

void createGameTree(int numSimulations) {
	while (currentNode->numSimulations() < numSimulations) {
		// (step A) selection - choose a new child to expand
		Node* node = currentNode;
		Node* child = NULL;
		int i = -1;
		while (node != NULL) {
			double maxPriority = 0;
			Node* maxNode = NULL;
			for (i = 0; i < node->children.size(); i++) {
				if (node->canProceed(validMoves[i]) == false) continue;
				child = node->children.at(i);
				if (child == NULL) goto EXPANSION;	// found a node to expand
				if (maxNode == NULL || child->priority() > maxPriority) {
					maxNode = child;
					maxPriority = child->priority();
				}
			}
			node = maxNode;
		}

		// (step B) expansion - add a new child to selected 'node'
		EXPANSION:
		if (node == NULL) break;	// reached terminal node, so no child to expand
		child = node->createChild(i, validMoves[i]);

		// (step C) simulation - from chosen child, randomly simulate game til it ends
		Node* copy = child->clone();
		int winner = copy->simulate();

		// (step D) update # of wins/losses and percolate these up toward root
		if (winner == treePlayer)
			child->updateNumbersTowardRoot(1, 0);
		else
			child->updateNumbersTowardRoot(0, 1);
	}
}

void proceedTreePlayerMove() {
	//cout << currentNode->toStringDFS() << endl;

	// choose a move on game tree with the highest winning rate
	double maxWinRate = 0;
	Node* maxNode = NULL;
	for (int i = 0; i < currentNode->children.size(); i++) {
		Node* node = currentNode->children.at(i);
		if (node == NULL) continue;
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
		if (node == NULL) continue;
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

	currentNode = new Node(numBlack, numWhite, currentPlayer);
	srand(time(0));	// seed pseudo-random-number generator with current time
	createGameTree(numSimulations);
	//cout << currentNode->toStringDFS() << endl;	
		
	while (true) {
		cout << currentNode->toString();
		if (currentNode->numBlack == 0 && currentNode->numWhite == 0) break;

		if (currentPlayer == treePlayer) {
			cout << ":Tree player (" << currentNode->numSimulations() << " simulations)" << endl;
			proceedTreePlayerMove();
			currentPlayer = randomPlayer;
		}
		else if (currentPlayer == randomPlayer) {
			cout << ":Random player" << endl;
			proceedRandomPlayerMove();
			currentPlayer = treePlayer;
		}

		// after each move, grow game tree beyond current node
		createGameTree(numSimulations);
	}

	if (currentPlayer == treePlayer) cout << ":Tree player won" << endl;
	else if (currentPlayer == randomPlayer) cout << ":Random player won" << endl;

	return 0;
}