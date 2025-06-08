## 📌 프로젝트 설명

`philo`는 고전적인 **철학자들의 식사 문제(Dining Philosophers Problem)**를 기반으로 한 멀티스레딩 과제입니다.  
스레드를 사용해 철학자들이 **교착 상태 없이** 식사하고 생각하고 잠드는 과정을 구현하며,  
**동기화(Synchronization)**와 **상호 배제(Mutual Exclusion)** 개념을 학습합니다.

---

## 🎯 과제 목표

- 스레드와 뮤텍스를 이용한 철학자 간 리소스 공유 문제 해결
- 교착 상태(deadlock) 및 경쟁 상태(race condition) 방지
- 식사 시간, 수면 시간, 생존 시간 등 조건 제어

---

## 🧠 핵심 규칙

1. 철학자는 포크를 **두 개 집어야** 식사 가능
2. 포크는 **양 옆 철학자와 공유**
3. `time_to_die` 안에 식사하지 못하면 사망
4. `time_to_eat`, `time_to_sleep`은 행동 지속 시간
5. (옵션) `must_eat_count` 만큼 먹은 뒤 모든 철학자가 종료 가능

---

## 🛠️ 사용 기술

- `pthread` 라이브러리
- `pthread_create`, `pthread_join`
- `pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`
- `gettimeofday`, `usleep`

---

## 🧱 구조 요약

- `philosopher` 구조체 배열
  - 철학자 번호, 상태, 마지막 식사 시간, 먹은 횟수 등 저장

- `fork` 배열 (뮤텍스)
  - 각 포크에 대해 뮤텍스 할당

- `monitor` 루틴
  - 각 철학자 스레드 상태 주기적으로 확인

- `time` 함수
  - 현재 시간 계산 및 밀리초 단위 수면 구현

---

## ⚙️ 실행 방법

```bash
$ make
$ ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [must_eat_count]
```

### 예시

```bash
$ ./philo 5 800 200 200
```

- 5명의 철학자
- 800ms 동안 식사 못하면 죽음
- 200ms 동안 식사, 200ms 동안 수면 반복

---

## ✅ 평가 기준

- 교착 상태 없이 모든 철학자가 일정 시간 이상 동작
- 시간 출력이 정렬되고 정확함
- `valgrind`를 통한 메모리 누수 없음
- 스레드/뮤텍스 초기화 및 종료 처리 확실

---

## 📚 학습 내용

- `pthread`를 통한 멀티스레딩 프로그래밍
- 경쟁 조건 해결 및 뮤텍스 제어
- 철학자 간 자원 공유 및 상태 추적
- 동기화 문제와 교착 상태 방지 전략
- 정밀 시간 제어 (`usleep`, `gettimeofday`)
