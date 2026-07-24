# 42Seoul Projects

42서울 과정에서 수행한 C/C++ 기반 프로젝트를 정리한 저장소입니다. 시스템 프로그래밍, 프로세스·파이프, 멀티스레딩, 네트워크 소켓, 컨테이너 환경을 직접 구현하며 동작 원리를 학습했습니다.

> 주로 42Seoul의 macOS 환경에서 구현했습니다. `kqueue`, MiniLibX, Readline 경로 등에 의존하는 프로젝트는 Linux나 Windows에서 추가 설정 없이 빌드되지 않을 수 있습니다.

## Featured Projects

### [minishell](./minishell)

2인 팀으로 Bash의 핵심 동작을 C와 POSIX 시스템 호출로 구현했습니다.

- **개인 담당**: 쿼트 상태 기반 파싱, 환경 변수·종료 상태 확장, 파이프·리디렉션·히어독 분석, 구문 오류 처리
- **팀 구현 범위**: 명령 실행, 빌트인, 파이프라인, 리디렉션, 환경 변수, 시그널
- **핵심 기술**: C, `fork`, `execve`, `pipe`, `dup2`, GNU Readline

### [ft_irc](./ft_irc)

3인 팀으로 RFC 1459의 기본 흐름을 참고한 IRC 서버를 C++98로 구현했습니다.

- **개인 담당**: `PASS`, `NICK`, `USER`, `JOIN`, `QUIT`
- **팀 구현 범위**: 사용자 등록, 채널 관리, 메시지 전송, numeric reply, BOT
- **핵심 기술**: C++98, TCP/IP, non-blocking socket, `kqueue`/`kevent`

## Project Map

| 분야 | 프로젝트 | 학습 내용 |
|---|---|---|
| C 기초 | [libft](./libft), [get_next_line](./get_next_line), [ft_printf](./ft_printf) | 표준 함수 재구현, 메모리·파일 디스크립터·가변 인자 |
| 알고리즘·그래픽 | [push_swap](./push_swap), [so_long](./so_long), [cub3D](./cub3D) | 스택 정렬, MiniLibX, raycasting |
| 시스템 프로그래밍 | [pipex](./pipex), [philo](./philo), [minishell](./minishell) | 프로세스·파이프·시그널, pthread, 동기화 |
| C++·네트워크 | [cpp_module](./cpp_module), [ft_irc](./ft_irc) | 객체지향, TCP socket, 이벤트 기반 서버 |
| 인프라·웹 | [inception](./inception), [ft_transcendence](./ft_transcendence) | Docker, NGINX, MariaDB, TypeScript 기반 웹 서비스 |

## Technical Focus

- C/C++ 기반 메모리·프로세스·파일 디스크립터 관리
- POSIX 시스템 호출을 이용한 명령 실행과 IPC
- pthread 동기화와 race condition 방지
- TCP socket과 이벤트 기반 다중 클라이언트 처리
- Makefile, Git, Docker를 이용한 빌드·개발 환경 구성

각 프로젝트의 세부 구현 범위와 한계는 해당 디렉터리의 README에 정리했습니다.
