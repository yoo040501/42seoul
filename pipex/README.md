## 📌 프로젝트 설명

리눅스의 **파이프(`|`) 기능을 구현**하는 프로젝트
쉘에서 사용하는 `cmd1 | cmd2` 명령처럼, 한 명령어의 출력을 다른 명령어의 입력으로 넘기는 동작을 C 언어로 직접 구현

---

## 🧠 구현 목표

- 두 개 이상의 명령어를 파이프로 연결하여 실행
- 명령어 간 입출력 흐름을 `pipe()`와 `dup2()`를 통해 제어
- 자식 프로세스를 `fork()`로 생성하여 명령어 실행

---

## 🧾 실행 형식

```bash
./pipex infile "cmd1" "cmd2" outfile
```

동작 방식:
```bash
< infile cmd1 | cmd2 > outfile
```

입력 파일 → `cmd1` 실행 → 출력은 `cmd2`의 입력 → 결과는 `outfile`에 저장

---

## 📄 필수 함수

- `pipe`, `fork`, `dup2`, `execve`
- `open`, `close`, `access`, `wait`, `perror`, `strerror`
- `malloc`, `free`, `exit`

---

## 🧱 기본 구조

1. **파일 오픈**
   - `infile`은 읽기 모드, `outfile`은 쓰기/생성 모드

2. **파이프 생성**
   - `pipe(fd)`를 사용하여 프로세스 간 통신 채널 생성

3. **fork()로 프로세스 분기**
   - 자식 프로세스는 각각 `cmd1`, `cmd2` 실행

4. **dup2()로 입출력 재지정**
   - `stdin`, `stdout`을 pipe 또는 파일로 재배치

5. **execve()로 명령 실행**
   - 경로 탐색 포함 (`PATH` 환경변수 사용)

---

## 🧪 예시

```bash
$ ./pipex infile "grep a" "wc -l" outfile
```

쉘에서:
```bash
< infile grep a | wc -l > outfile
```

---

## 🧹 에러 처리

- 파일 열기 실패
- 명령어 경로 탐색 실패
- `fork`, `pipe`, `dup2` 실패
- 잘못된 인자 수
- 메모리 누수, 자원 미해제 등

---

## 🎁 보너스 (pipex_bonus)

- **N개의 명령어**를 파이프라인으로 연결 (`cmd1 | cmd2 | ... | cmdN`)
- **here_doc** 기능 구현:

```bash
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```

쉘에서:
```bash
<< LIMITER cmd1 | cmd2 >> outfile
```

사용자가 `LIMITER`를 입력할 때까지 표준 입력을 받아 첫 명령어의 입력으로 사용

---

## ✅ 평가 기준

- 정상 동작 여부 (입출력 정확성)
- 명령어 실행 정확성 (execve, 경로 탐색)
- 부모/자식 간 자원 분리 및 프로세스 종료 관리
- 메모리 누수 없음
- 에러 메시지 및 예외 처리

---

## 📚 학습 내용

- 유닉스 시스템 콜 (`pipe`, `fork`, `execve`, `dup2`)
- 입출력 리디렉션 원리
- 환경 변수(`PATH`)를 통한 명령어 탐색
- 자식 프로세스 관리 (`wait`)
- 보안적인 자원 해제 및 오류 처리

---
