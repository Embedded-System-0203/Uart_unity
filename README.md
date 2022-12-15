# Uart_unity

# 통신 기능을 구현하면서 발생한 문제점들
- 기존의 블루투스 모듈 HC-06을 사용해 양방향 통신을 수행하고자 했지만 단방향 통신만 가능해 USB to Serial 모듈 PL2303HXA를 구매해 사용.

  <h4>--> 22.12.10) PL2303HXA를 사용해 양방향 통신을 시도했고 정상적으로 작동함을 확인. 장치의 문제라고 생각했지만 소스코드의 문제인 것을 알게 되었고,
  블루투스 모듈 HC-06을 사용해 제대로 동작하는 지 확인할 예정.</h4>
  
  <h4>--> 22.12.11) 블루투스 모듈 HC-06을 사용해보니 정상적으로 작동함을 확인. USB to Serial 모듈 대신 블루투스 모듈을 사용하기로 결정.</h4>

- Ardity를 사용해 유니티와 라즈베리 파이 사이에 양방향 통신을 수행하고자 했지만, 단방향 통신(유니티 -> 라즈베리 파이)만 동작했음.
  
  <h4>--> 22.12.10) "AbstractSerialThread.cs"에 있는 "ReadFromWire"함수가 제대로 동작하지 않아 "RunOnce"함수에 기능을 새로 구현.</h4>
  
- 유니티 -> 라즈베리 파이로 데이터를 보내면 라즈베리 파이에서 보낸 적 없는 공백문자들이 같이 출력됨.

  <h4>--> 22.12.11) "AbstractSerialThread.cs"에 있는 "SendToWire"함수가 제대로 동작하지 않는 것을 확인하고 "RunOnce"함수에 기능을 새로 구현.</h4>

# Port Name 확인 방법
1) "Bluetooth 및 기타 장치" 우측에 있는 "추가 Bluetooth 옵션" 클릭.
2) "COM 포트"에 있는 방향이 "송신"인 포트 이름을 확인.

# Unity Settings
1) 좌측 상단 "Edit" - "Project Settings" - "Player" - "Other Settings" - "Configuration" - "Api Compatibility Level"에서 ".NET Framework" or ".NET 4.x"를 선택.
2) 좌측 하단 "Project" - "Assets" - "Ardity" - "Scenes" - "DemoScene_UserPoll_ReadWrite"를 왼쪽 상단 "Hierarchy"에 드래그 앤 드랍.
3) "Hierarchy"에 있는 "SerialController"를 클릭한 뒤, "Inspector"에 보이는 "Serial Controller (Script)"에서 "Port Name"과 "Baud Rate"(=115200)를 수정.

# Unity 변경 사항
- Ardity에서 제공하는 송수신 기능이 라즈베리 파이에선 제대로 동작하지 않아 송수신 기능을 새로 구현.
- 송수신을 수행하면서 딜레이가 너무 작으면, 데이터가 끊겨서 들어오는 경우가 발생해 딜레이를 추가.

# 라즈베리 파이 소스코드
- 라즈베리 파이와 유니티 기본적인 송수신 기능
- 임베디드 장치와 유니티를 사용해 "ParkingSimulator" 기능을 수행하는 소스코드는 "ParkingSimulator" repository에 업로드할 예정.
