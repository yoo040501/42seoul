# get_next_line

## 📌 프로젝트 설명

파일 디스크립터로부터 **한 줄씩** 읽어오는 함수를 구현하는 프로젝트.  
제한된 함수만을 사용하여 효율적인 **버퍼 관리**와 **메모리 안정성**을 보장하는 것이 핵심이며, 보너스에서는 여러 파일 디스크립터를 동시에 처리할 수 있어야 합니다.

---

## 📄 함수 원형

```c
char *get_next_line(int fd);
```

- 호출할 때마다 한 줄을 반환 (`\n` 포함)
- 읽을 것이 없거나 오류 시 `NULL` 반환
- 여러 파일 디스크립터 동시 처리 가능 (보너스)

---

## 🧠 구현 개요

- **잔여 버퍼**를 `static` 변수로 관리
- `read()`를 통해 `BUFFER_SIZE`만큼 읽고 누적
- 개행 문자 기준으로 줄 분리
- 반환 후 남은 문자열은 다음 호출을 위해 저장
- 파일 끝(EOF) 또는 오류 시 `NULL` 반환

---

## 🎁 보너스 기능

- 복수의 `fd`에 대해 각각 별도의 상태를 유지
- `get_next_line`이 여러 파일을 병렬로 읽을 수 있도록 구현
- 구조체 및 리스트를 활용한 `fd`별 버퍼 저장

---

## 🛠️ 기술 스택

- **언어**: C  
- **제한 함수**: `read`, `malloc`, `free`  
- **코딩 스타일**: 42 Norm  

---

## 🏗️ 컴파일 예시

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

> `BUFFER_SIZE`는 컴파일 타임에 정의 필요

---

## 💻 사용 예시

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("sample.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## 📚 학습 내용

- 파일 디스크립터 및 시스템 호출 이해 (`read`)
- 문자열 처리 및 동적 메모리 관리
- static 변수와 상태 유지
- 효율적인 입출력 처리 (I/O buffering)
- 복수 파일 디스크립터 핸들링 (보너스)

---

## ✅ 평가 포인트

- 메모리 누수 없음 (`valgrind` 통과)
- 한 줄 단위 정확한 반환 (`\n` 포함)
- EOF 처리 정확성
- 다중 파일 디스크립터 동시 지원 (보너스)
- 버퍼 크기 변경 대응 가능 (`BUFFER_SIZE`)

---

> 🏁 `get_next_line`은 C 언어로 low-level I/O와 버퍼링 구조를 깊이 이해하는 데 중요한 과제이며, 이후 `minishell`, `pipex` 같은 프로젝트에서도 핵심적인 기반이 됩니다.
