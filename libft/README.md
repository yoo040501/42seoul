# Libft

## 📌 프로젝트 설명

Libft는 42서울 과정에서 처음으로 수행하는 프로젝트로, C 표준 라이브러리의 일부 함수들을 직접 구현하여 C 언어의 기본적인 동작 원리와 메모리 관리를 학습하는 것을 목표로 합니다.  
또한 개인 라이브러리를 작성하여 이후의 모든 프로젝트에서 재사용 가능하도록 설계합니다.

---

## 🔧 주요 구현 함수

### 🟦 Part 1 – Libc functions (기초 함수)
- `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
- `ft_strlen`, `ft_strlcpy`, `ft_strlcat`
- `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`
- `ft_atoi`, `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- `ft_toupper`, `ft_tolower`
- `ft_calloc`, `ft_strdup`

### 🟦 Part 2 – Additional functions (보조 함수)
- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`
- `ft_itoa`, `ft_strmapi`, `ft_striteri`
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### 🟦 Bonus Part – Linked list (보너스)
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`
- `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

---

## 🧠 학습한 점

- 메모리 할당과 해제 (`malloc`, `free`)
- 포인터 연산 및 배열 다루기
- 문자열 처리 함수의 동작 원리
- 연결 리스트의 기본 구조 및 함수 구현
- 코드 스타일 및 반복적인 테스트를 통한 디버깅 습관

---

## 🛠 사용 기술

- **언어**: C
- **빌드**: Makefile
- **도구**: `ar`, `ranlib`, `gcc`, `valgrind`
- **기준**: 42 Norm (코딩 스타일 규칙)

---

## ✅ 빌드 방법

```bash
make            # libft.a 생성
make clean      # 오브젝트 파일 삭제
make fclean     # 오브젝트 파일 및 libft.a 삭제
make re         # 재빌드
