# ft_irc

RFC 1459의 기본 흐름을 참고해 C++98로 구현한 IRC 서버입니다. TCP 소켓과 비차단 I/O, macOS의 `kqueue`/`kevent`를 이용해 여러 클라이언트의 접속과 채널 기반 메시지 교환을 처리합니다.

## 프로젝트 정보

- 42Seoul 3인 팀 프로젝트
- 언어: C++98
- 실행 환경: macOS
- 네트워크: TCP/IP, non-blocking socket
- 이벤트 처리: `kqueue`, `kevent`

## 서버 처리 흐름

```text
socket → bind → listen
                  ↓
           kqueue event loop
                  ↓
              accept/recv
                  ↓
         개행 확인과 명령 분기
                  ↓
       인증·채널·메시지 명령 처리
```

각 연결은 `Client` 객체로 관리하며, 수신 문자열에서 명령을 추출한 뒤 인증 상태에 따라 명령 처리 함수로 분기합니다.

## 팀 전체 구현 범위

- 서버 소켓 생성 및 비차단 연결 관리
- PASS/NICK/USER 기반 사용자 등록
- 채널 생성·참여·퇴장과 운영자 권한 관리
- 사용자·채널 대상 메시지 전송
- IRC numeric reply와 오류 응답
- 간단한 BOT 기능

구현된 주요 명령:

| 분류 | 명령 |
|---|---|
| 인증·연결 | `PASS`, `NICK`, `USER`, `QUIT`, `PING` |
| 채널 | `JOIN`, `PART`, `TOPIC`, `MODE`, `INVITE`, `KICK` |
| 메시지 | `PRIVMSG` |
| 부가 기능 | `BOT` |

## 개인 담당

팀 전체 구현과 개인 담당을 구분합니다. 개인적으로 담당한 핵심 범위는 다음과 같습니다.

- `PASS`: 서버 비밀번호 검증과 인증 상태 처리
- `NICK`: 닉네임 유효성·중복 검사와 변경 전파
- `USER`: 사용자 정보 파싱 및 등록
- `JOIN`: 채널 생성·참여와 채널 상태 갱신
- `QUIT`: 연결 종료 시 사용자·채널 정보 정리

## 빌드 및 실행

```bash
make
./ircserv <port> <password>
```

접속 예시:

```bash
nc 127.0.0.1 6667
PASS secret
NICK guest
USER guest 0 * :guest user
JOIN #test
PRIVMSG #test :hello
QUIT
```

## 확인할 테스트 시나리오

- 여러 클라이언트의 동시 접속
- 인증 전·후 명령 분기
- 중복 닉네임과 잘못된 닉네임
- 채널 생성, 참여, 퇴장, 운영자 권한
- 한 패킷에 복수 명령 수신
- 하나의 명령이 여러 패킷으로 분할 수신
- 연결 종료 후 채널과 닉네임 상태 정리

## 한계

- 이벤트 루프가 macOS의 `kqueue`에 의존하므로 Linux에서는 그대로 빌드되지 않습니다.
- RFC 1459 전체를 구현한 서버가 아니라 교육 프로젝트에서 요구한 핵심 흐름을 구현한 서버입니다.
- 비차단 소켓의 대용량 송신을 위한 별도 출력 큐는 구현하지 않았습니다.
- 수신 버퍼는 서버 단위로 구성돼 있어 클라이언트별 패킷 프레이밍은 향후 개선 항목입니다.
