# :bomb: Minesweeper :bomb:
C++을 이용해 지뢰 찾기 게임 구현하기
## 함수 기능 설명
### (1) minesweeper
- 명령 코드들이 적혀있는 파일의 파일명과, 그 명령 코드들을 수행한 결과물을 기록할 (output)파일명을 입력값으로 받는다.</br>
- 8*8의 배열 변수를 두 개 만들어 두고, 한 변수는 기본 '.'가 들어가 있는 행렬, 그리고 또 다른 변수는 게임에 이용될 지뢰의 위치가 담긴 행렬을 담는 변수로 이용한다.
- 명령어 파일을 읽어들여, 명령어가 load, display, touch 인 경우, 그리고 게임 종료 조건인 경우에 따라 실행이 다르게 되도록 while문과 if문을 활용한다.
- 게임 종료 조건:</br> 
1. 지뢰를 건드리지 않고 touch를 한 수가 54회인 경우 게임 종료.</br> 
2. 지뢰를 건드린 경우 게임 종료.</br>
3. 더 이상 명령이 없는 경우 게임 종료.

### (2) load
- 지뢰 위치가 명시된 8*8 행렬 정보를 저장하고 있는 board 파일을 입력으로 받고, 그 파일에 저장된 행렬 정보를 기존에 만들어둔 8*8 배열 변수에 옮긴다.

### (3) touch
- 지뢰 위치가 저장된 배열과, 백지 상태의 배열을 활용한다. touch한 지점의 종류에 따라 백지 상태의 배열을 다른 값으로 초기화 한다.</br>
- 8*8 행렬 이외의 지점을 선택한 경우 아무 반응이 일어나지 않도록 한다. </br>
- 지뢰를 건드린 경우, 그 지점을 '*' 로 초기화 하고, touch 횟수에 1을 더하고, 프로그램이 종료되도록 bool 변수를 false로 초기화한다. </br>
- 지뢰가 아닌 지점을 건드린 경우, touch 횟수에 1을 더하고, 주위에 위치한 지뢰의 갯수를 int형으로 구한 뒤 char형으로 바꾸어 그 지점을 초기화한다.</br>

### (4) display
- 지뢰 위치가 저장된 배열이 아닌, 게임 진행에 따라 초기화되고 있는 8*8 크기의 배열을 output파일에 기록한다.

## (5) endgame
- 초기화 하고 있던 배열에서 건드리지 않은 지뢰들은 모두 '@'로 초기화한 뒤, 해당 배열을 output파일에 기록한다 
