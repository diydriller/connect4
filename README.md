# connect4


* 게임설명

  connect4는 중력빙고 게임으로 가로 세로 대각선방향으로 4돌을 두면 이기는 게임이다.
  콘솔 환경에서 작동하며 선수(X)와 후수(O)를 선택할수있고 AI보다 4돌을 먼저 두면 이긴다.

  <div>
  <img width="241" alt="dd" src="https://user-images.githubusercontent.com/41245313/92613255-b96c1900-f2f5-11ea-9ba0-ccf70939dee7.png">
  <img width="230" alt="hhh" src="https://user-images.githubusercontent.com/41245313/92614665-42d01b00-f2f7-11ea-90a4-d128626b2006.png">
  <img width="220" alt="rrrr" src="https://user-images.githubusercontent.com/41245313/92615034-a6f2df00-f2f7-11ea-84d8-c4fad4a916c8.png">

  </div>

* 사용언어 

  C++

* 파일설명

  main.cpp - 사용자의 입력받고 게임을 진행

  tree.cpp tree.h - AI가 수를 둘때 사용하는 game tree 

  board.cpp board.h  - 게임이 진행되는 board판
  
  minmax.cpp minmax.h - AI가 수를 둘때 사용하는 minmax알고리즘 
  

* 구현사항
  * do while문을 사용해서 승자가 발생하면 게임을 중단하고 아니면 게임을 진행한다.
  * 사용자가 선수를 두는지 후수를 두는지와 사용자차례인지 AI차례인지에따라 4가지 부분으로 나눈다. 
  * AI가 수를 둘때 깊이가 8인 game tree를 사용해서 8수 앞의 상황을 평가함수를 통해 점수화하고 minmax 알고리즘을 통해
    수를 선택하고 board판에 기록한다.
  * 성능향상을 위해 game tree의 각 깊이마다 점수를 계산하고 기존의 점수에 더해준다. 이때 얕은 깊이일수록 가중치를 더 준다.
  * 객체 복사시 shallow copy가 발생해서 operator=를 overloading함으로써 deep copy를 해주었다.
  



