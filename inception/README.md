## 📌 프로젝트 설명

**Docker**를 활용해 리눅스 서버 환경을 구성하는 프로젝트입니다.  
여러 개의 서비스를 각각 독립된 **컨테이너**에서 동작시키고,  
모든 구성 요소를 **Docker Compose**로 관리하여 실제 서비스 배포의 기본을 실습합니다.

---

## 🔧 구현 서비스

본 프로젝트에서는 다음과 같은 서비스를 각각 독립된 Docker 컨테이너로 구성했습니다:

| 서비스         | 설명                                                       |
|----------------|------------------------------------------------------------|
| **Nginx**       | HTTPS 설정된 리버스 프록시 서버 (SSL/TLS 인증서 사용)      |
| **WordPress**   | 동적 웹사이트 (PHP 기반 CMS)                               |
| **MariaDB**     | WordPress의 데이터 저장을 위한 MySQL 호환 데이터베이스      |
| **Redis**       | 세션/캐시 관리를 위한 인메모리 데이터 저장소 (선택)        |
| **Adminer**     | 데이터베이스 웹 관리 툴 (선택)                             |
| **FTP**         | 정적 파일 전송을 위한 FTP 서버 (선택)                      |

> 🧱 모든 컨테이너는 **Dockerfile**을 통해 개별적으로 빌드되며,  
> **Docker Compose**를 통해 한 번에 오케스트레이션됩니다.

---

## 🧠 핵심 구성 요소

- **Docker**
  - 서비스별 `Dockerfile` 작성
  - `alpine` 베이스 이미지 기반 경량 컨테이너

- **Docker Compose**
  - `docker-compose.yml`로 전체 서비스 조합 정의
  - 네트워크/볼륨 자동 생성 및 연결

- **볼륨**
  - DB 및 WordPress 데이터를 위한 볼륨 구성 (데이터 지속성 보장)

- **SSL 인증서**
  - `openssl`을 통해 **자체 서명된 인증서(self-signed certificate)** 생성 및 Nginx 적용

---

## 🗂️ 프로젝트 구조 예시

```
inception/
├── srcs/
│   ├── requirements/
│   │   ├── nginx/
│   │   │   ├── Dockerfile
│   │   │   └── default.conf
│   │   ├── wordpress/
│   │   │   └── Dockerfile
│   │   ├── mariadb/
│   │   │   └── Dockerfile
│   │   └── ...
│   ├── docker-compose.yml
│   └── .env
└── README.md
```

---

## 🛠️ 사용 방법

### 1. 실행 준비

```bash
cd srcs
cp .env.example .env # 환경 변수 설정 (예: WP_USER, DB_PASSWORD 등)
```

### 2. 컨테이너 실행

```bash
docker compose up --build
```

### 3. 서비스 접속

- https://localhost
- WordPress 설치 화면 접속 가능
- phpMyAdmin/Adminer로 DB 접속 가능

---

## 📚 학습 내용

- Docker 이미지, 컨테이너, 볼륨, 네트워크 개념
- Docker Compose의 서비스 정의 방식
- SSL 인증서 생성 및 적용
- LEMP 스택 (Linux + Nginx + MariaDB + PHP)
- 서비스간 연결과 포트 포워딩, 환경 변수 활용
- 실제 웹 애플리케이션의 배포 흐름

---

## ✅ 평가 항목

- 컨테이너별 `Dockerfile` 작성 여부
- `docker-compose.yml` 정확성 및 서비스 정상 동작
- 볼륨을 통한 데이터 지속성 구현
- Nginx에서 HTTPS 적용 및 WordPress 접근 가능 여부
- 컨테이너 간 의존성 정확히 설정
- 보안 설정 및 환경 변수 사용
