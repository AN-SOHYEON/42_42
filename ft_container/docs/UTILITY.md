

## 함수 객체, function object
- 일반 함수 객체
	- 산술 연산 함수 객체
		: +, -, ...
	- 비교 연산 함수 객체 조건자
		: equal_to, less, greater, ...
	- 논리 연산 함수 객체 조건자
		: logical_and, logical_or, ...
- 함수 어댑터
	- binder
		: 이항 함수 객체를 단항 함수 객체로 변환
	- negator
		: 함수 객체 조건자를 반대로 변환
	- 함수 포인터 어댑터
		: 함수 포인터를 STL이 요구하는 함수 객체로 변환
	- 멤버 함수 포인터 어댑터
		: 멤버 함수 포인터를 STL이 요구하는 함수 객체로 변환
### 조건자
조건을 판단해야하는 대부분의 알고리즘에 사용된다. 
조건자는 상태를 변환할 수 없어 const를 붙여야 한다. 
### binder



### equal()
```
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
```
first2부터 [first1, last1) 구간과 같은 원소가 순서대로 있는지?

### lexicographical_compare()
```
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
```
구간[first1, last1)의 순차열이 구간[first2, last2)의 순차역보다 작다면(사전순으로) true, 아니라면 false