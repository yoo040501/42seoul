# ft_printf

## 📌 프로젝트 설명

C 표준 라이브러리의 `printf` 함수와 비슷한 동작을 하는 출력을 직접 구현하는 프로젝트.  
가장 기본적이면서도 복잡한 기능을 요구하는 과제로, **가변 인자 처리**, **포맷 문자열 파싱**, 그리고 **출력 함수의 구조화** 능력을 키울 수 있습니다.

---

## 🎯 구현 대상

아래의 포맷 문자들을 처리해야 합니다:

| 포맷 | 설명                  |
|------|-----------------------|
| `%c` | 문자 출력             |
| `%s` | 문자열 출력           |
| `%p` | 포인터 주소 출력      |
| `%d` | 부호 있는 10진수 출력 |
| `%i` | 부호 있는 10진수 출력 |
| `%u` | 부호 없는 10진수 출력 |
| `%x` | 16진수 (소문자) 출력  |
| `%X` | 16진수 (대문자) 출력  |
| `%%` | 퍼센트 문자 출력      |

---

## 📄 함수 원형

```c
int ft_printf(const char *format, ...);
```

- `va_list`, `va_start`, `va_arg`, `va_end` 사용
- 가변 인자를 이용한 포맷 처리
- 성공적으로 출력된 문자 수 반환

---

## 🧠 구현 개요

- `write()`로 직접 출력
- 각 포맷 타입마다 개별 처리 함수 구성 (`ft_print_char`, `ft_print_str`, ...)
- `%` 문자 발견 시 포맷 문자 판단 후 분기 처리
- 숫자 변환을 위한 itoa/utoa/hex 변환기 구현
- 포인터 주소는 `0x` 접두사와 함께 16진수로 출력

---

## 🛠️ 기술 스택

- **언어**: C  
- **가변 인자 처리**: `stdarg.h`  
- **출력 함수**: `write()`  
- **메모리 관리**: 동적 할당 없음 (필요 시 libft 활용)  
- **코딩 스타일**: 42 Norm  

---

## 🏗️ 컴파일 예시

```bash
gcc -Wall -Wextra -Werror ft_printf.c ft_printf_utils.c -o ft_printf_test
```

---

## 💻 사용 예시

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello, %s!\n", "world");
    ft_printf("Printed %d characters.\n", count);
    ft_printf("Pointer: %p\n", &count);
    ft_printf("Hex: %x | HEX: %X\n", 255, 255);
    ft_printf("Char: %c, Percent: %%\n", 'A');

    return 0;
}
```

---

## 📚 학습 내용

- `printf`의 내부 동작 방식 이해
- 가변 인자 처리 (`va_list`)
- 포맷 파싱 및 분기 처리
- 숫자 변환 및 문자열 구성
- 엣지 케이스 처리 (NULL 문자열, 0, 음수 등)

---

## ✅ 평가 포인트

- 정상 출력 여부
- 반환값(출력된 글자 수)의 정확성
- 다양한 포맷 타입에 대한 대응
- 메모리 누수 없음
- 42 Norm 및 권장 구현 방식 준수

---
