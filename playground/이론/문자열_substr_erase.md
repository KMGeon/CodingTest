# C++ string 클래스의 substr와 erase 함수 완벽 가이드

## 1. substr() - 부분 문자열 추출

### 기본 문법
```cpp
string.substr(시작위치, 길이)
```

### 매개변수
- **시작위치 (pos)**: 추출을 시작할 인덱스 (0부터 시작)
- **길이 (len)**: 추출할 문자 개수 (생략 가능)

### 예제

```cpp
string str = "Hello World";

// 1. 시작위치만 지정 (끝까지 추출)
str.substr(6)        // "World"

// 2. 시작위치 + 길이 지정
str.substr(0, 5)     // "Hello"
str.substr(6, 3)     // "Wor"

// 3. 마지막 n개 문자 추출
str.substr(str.size() - 5)  // "World" (마지막 5개)
str.substr(str.size() - 3, 3)  // "rld" (마지막 3개)
```

### 인덱스 이해하기

```
string str = "Hello World";
             
인덱스:      0 1 2 3 4 5 6 7 8 9 10
문자:        H e l l o   W o r l d

str.substr(6, 5)
           ↑     ↑
         시작   길이
         
결과: "World"
```

### 실전 활용

```cpp
string temp = "abcC4";
string tg = "C4";

// 마지막 2글자 추출
temp.substr(temp.size() - tg.size(), tg.size())
// = temp.substr(5 - 2, 2)
// = temp.substr(3, 2)
// = "C4"
```

---

## 2. erase() - 문자열 삭제

### 문법 종류

#### 방법 1: 위치와 길이로 삭제
```cpp
string.erase(시작위치, 길이)
```

#### 방법 2: 반복자(iterator)로 삭제
```cpp
string.erase(시작_반복자, 끝_반복자)
```

### 예제

```cpp
string str = "Hello World";

// 방법 1: 인덱스 사용
str.erase(5, 6);     // "Hello" (인덱스 5부터 6개 삭제)

str = "Hello World";
str.erase(0, 6);     // "World" (처음부터 6개 삭제)

// 방법 2: 반복자 사용
str = "Hello World";
str.erase(str.begin() + 5, str.end());  // "Hello"

str = "Hello World";
str.erase(str.begin(), str.begin() + 6);  // "World"
```

### 반복자(Iterator) 이해하기

```cpp
string str = "Hello";

str.begin()     // 첫 번째 문자를 가리킴 ('H')
str.end()       // 마지막 다음을 가리킴 (끝 표시)

str.begin() + 2 // 세 번째 문자를 가리킴 ('l')
str.end() - 1   // 마지막 문자를 가리킴 ('o')
```

```
str = "H e l l o"
       ↑       ↑ ↑
    begin()    │ end()
           end()-1
```

### 마지막 n개 문자 삭제

```cpp
string str = "Hello World";

// 마지막 5개 삭제
str.erase(str.end() - 5, str.end());
// 결과: "Hello "

// 마지막 1개 삭제
str.erase(str.end() - 1, str.end());
// 또는
str.pop_back();  // 더 간단!
```

---

## 3. 코드에서의 활용

### substr 사용 부분
```cpp
temp.substr(temp.size() - tg.size(), tg.size())
```

**예시:**
```cpp
temp = "mirkovC4"  (길이: 8)
tg = "C4"          (길이: 2)

temp.substr(8 - 2, 2)
= temp.substr(6, 2)
= "C4"  ✓ 마지막 2개 문자 추출
```

### erase 사용 부분
```cpp
temp.erase(temp.end() - tg.size(), temp.end())
```

**예시:**
```cpp
temp = "mirkovC4"
tg = "C4"

temp.erase(temp.end() - 2, temp.end())
```

**시각화:**
```
temp = "m i r k o v C 4"
                    ↑   ↑
              end()-2  end()
              
이 범위를 삭제 → "mirkov"
```

---

## 4. 주요 차이점 정리

| 함수 | 기능 | 원본 변경 | 반환값 |
|------|------|-----------|--------|
| `substr()` | 부분 문자열 **추출** | ❌ 변경 안함 | 새로운 string |
| `erase()` | 부분 문자열 **삭제** | ✅ 원본 수정 | 수정된 string& |

### 예제
```cpp
string str = "Hello World";

// substr: 원본 유지
string sub = str.substr(0, 5);
cout << str;  // "Hello World" (원본 그대로)
cout << sub;  // "Hello"

// erase: 원본 수정
str.erase(0, 6);
cout << str;  // "World" (원본이 변경됨)
```

---

## 5. 실전 팁

### 빈 문자열 체크
```cpp
// 방법 1
if (str.size() == 0) { }

// 방법 2 (추천)
if (str.empty()) { }

// 방법 3
if (!str.size()) { }
```

### 마지막 문자 접근
```cpp
string str = "Hello";

// 읽기
char last = str[str.size() - 1];  // 'o'
char last = str.back();           // 'o' (더 안전)

// 삭제
str.erase(str.end() - 1);
str.pop_back();                   // 더 간단!
```

### 문자열 끝 비교
```cpp
string temp = "abcde";
string pattern = "de";

// 끝부분이 pattern과 같은지 확인
if (temp.size() >= pattern.size() &&
    temp.substr(temp.size() - pattern.size()) == pattern) {
    // 일치!
}
```

---

## 6. 시간 복잡도

| 연산 | 시간 복잡도 |
|------|-------------|
| `substr(pos, len)` | O(len) |
| `erase(pos, len)` | O(n) - n은 문자열 길이 |
| `erase(it1, it2)` | O(거리 + 뒤 문자 이동) |

**주의:** `erase`는 삭제 후 뒤의 문자들을 앞으로 이동시키므로 비용이 큽니다!

---

이제 `substr`와 `erase`를 완벽하게 이해하셨을 겁니다! 🎯