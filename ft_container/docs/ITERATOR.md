## iterator

- input iterator : 현 위치의 원소를 한 번만 읽을 수 있다.
	-> istream
- output iterator : 현 위치의 원소를 한 번만 쓸 수 있다.
	-> ostream
- forward iterator : 입출력 반복자 + 순방향(++)으로 이동 가능

- bidirectional iterator : forward + 역방향(--)으로 이동 가능
	-> list, set, map
- random access iterator : bidirectional + (+, -, +=, -=, [])연산 가능
	-> vector, deque

---

### X::iterator && X::const_iterator
iterator로 선언하면 반복자로 가리키는 원소의 읽기, 쓰기가 가능하고
const_iterator로 선언하면 반복자로 가리키는 원소의 읽기만 가능하다.

반복자가 가리키는 원소의 위치를 변경하지 않으려면 const 키워드를 사용하여 반복자를 const화할 수 있다. 
```
vector<int>::iterator iter = v.begin();
vector<int>::const_iterator citer = v.begin() + 1;
const vector<int>::iterator const_iter = v.begin() + 2;
const vector<int>::const_iterator const_citer = v.begin() + 3;
```
iter -> 가리키는 원소 변경 가능 (*iter = 100;)
iter -> 반복자 변경 가능 (++iter;)

citer -> 가리키는 원소 변경 불가능 
citer -> 반복자 변경 가능 

const_iter -> 가리키는 원소 변경 가능 
const_iter -> 반복자 변경 불가능 

const_citer -> 가리키는 원소 변경 불가능 
const_citer -> 반복자 변경 불가능

### reverse_iterator
정방향 반복자가 가리키는 원소와 값은 모두 같지만 역방향 반복자는 가리키는 원소의 실제 값이 지금 가리키는 원소의 다음(++)원소가 된다.
-> 알고리즘 수행 시 정방향 반복자와 호환되도록 하기 위해서


## std::iterator_traits

각 반복자는 종류에 따라 자신만의 특징을 가지며 이 특징을 저장하는 템플릿 클래스를 iterator_traits라고 한다. 또한 반복자를 지원하는 두 함수 advance()와 distance()함수로 임의 접근 반복자만이 가지고 있는 연산을 다른 반복자도 가능하게 지원한다.

- 정의
	반복자의 형식을 확인하기 위해 특징 정보 클래스 iterator_traits를 제공한다.
```
template <typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type; 
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
	};
```
+ iterator_tag 
반복자의 종류를 구분할 수 있게 하는 반복자 태그
```
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};
```
	- 같은 함수라도 반복자 테그를 통해서 각 반복자에 알맞게 오버로딩된 함수를 호출할 수 있다.

### distance()
distance()는 반복자 간의 차이(difference_type)를 반환한다. 이때 random_access iterator(배열기반)는 단순히 이터레이터간 뺄셈으로 차이를 알 수 있지만 bidirectional iterator(노드기반)는 불가능하다. 따라서 distance()함수를 통해서 iterator간 차이를 알아낼 수 있다. 
```
iterator_traits<vector<int>::iterator>::difference_type n = distance(v.begin(), v.end());
```
