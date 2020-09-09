# connect4


* 게임설명

connect4는 중력빙고 게임으로 가로 세로 대각선방향으로 4돌을 두면 이기는 게임이다.
콘솔 환경에서 작동하며 선수(X)와 후수(O)를 선택할수있고 AI보다 4돌을 먼저 두면 이긴다.

* 사용언어 

C++

* 파일설명

main.cpp  사용자의 입력받고 게임을 진행

tree.cpp  AI가 수를 둘때 사용하는 game tree 
tree.h 

board.cpp  게임이 진행되는 board판
board.h

minmax.cpp  AI가 수를 둘때 사용하는 minmax알고리즘 
minmax.h

cf) 
1. 객체 복사시 shallow copy가 발생해서 operator=를 overloading함으로써 deep copy를 해주었다.
2. game tree의 leaf node에서는 8수 앞을 가정해서 score를 계산하고 minmax알고리즘을 통해 score가
가장 높은 수를 선택했는데 너무 앞의 상황에 치중해 현재 상황에 좋지않은 수를 두는 문제가 생겨서 
각 깊이마다 score를 기존score에 합해주었고 얕은 깊이일수록 가중치를 더 주었다.



