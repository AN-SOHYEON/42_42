## ft_container

## general rules


#### Formatting and naming conventions
- 적절한 이름의 class 파일에 각 컨테이너를 작성하세요
- norminette은 없습니다만 동료가 이해하지 못할 코드를 작성하지 마세요. 깔끔하고 읽기 쉽게 작성하도록 최선을 다하세요.

#### Allowed / Forbidden
- standard library의 모든 형식을 사용할 수 있습니다. c에 젖어있지 말고 가능한 c++을 활용하세요.
- external library는 사용할 수 없습니다. 즉 c++11과 Boost library들은 사용금지입니다.
- *printf(), *alloc(), free() 또한 금지입니다. 

#### few design requirements
- 메모리를 할당할 때 메모리누수가 나서는 안됩니다. 
- 함수의 구현을 헤더파일에 하면 0접입니다. (함수 템플릿 제외하고)
- 각 헤더가 독립적이여야 합니다. 따라서 각자 필요한 의존성을 각자 알아서 포함하고 있어야 합니다. 그러나 include guards를 통해서 중복된 inclusion의 문제를 해결하지 않았다면 0점입니다. 


### 
STL container를 구현하는 과제이니 당연히 구현을 위해 STL container를 사용하면 안됩니다. 

#### requirements
- namespace는 ft 여야 합니다. 
- 구현한 container에서 사용된 각 inner data structure는 논리적이고 정당성이 있어야 합니다. (그냥 단순 배열로 map을 구현해서는 안된다는 말입니다.)
- 


---
## Mandatory part
- vector
	- vector<bool>은 구현할 필요 없습니다. 
- map
- stack

- std::iterator_traits
- std::reverse_iterator
- std::enable_if
	: SFINAE
- std::is_integral
- std::equal and/or std::lexicographical_compare
- std::pair
- std::make_pair

---
## STL, standard Template Library
- 프로그램에 필요한 자료구조와 알고리즘을 템플릿으로 제공하는 라이브러리
	- 효율성
	- 재사용성
	- 확장성

- 컨테이너, container
	- 객체를 저장하는 객체
	- 컬렉션, 자료구조
- 반복자, iterator 
	- 컨테이너의 원소를 가리키고, 그 원소에 접근하여 다음 원소를 가리키도록 한다.
	- 포인터를 추상화한 클래스 객체
- 함수 객체, function Object
	- 함수처럼 동작하는 객체로 operator() 연산자를 오버로딩한 객체
	- 컨테이너와 알고리즘 등에 클라이언트 정책을 반영하게 한다. 
- 어댑터, Adaptor 
	- 구성 요소의 인터페이스를 변경하여 새로운 인터페이스를 갖는 구성 요소처럼 보이게 한다.
- 할당기, Allocator
	- 컨테이너의 메모리 할당 정책을 캡슐화한 클래스 객체
	- 모든 컨테이너는 자신만의 기본 할당기를 가진다.

### 컨테이너
- standard sequence container
	- 컨테이너 원소가 자신만의 삽입 위치를 가지는 컨테이너
	- vector, list, deque
- standard associative container
	- 저장 원소가 삽입 순서와 다르게 특정 정렬 기준에 의해 자동 정렬되는 컨테이너
	- set, map, multiset, multimap


### iterator
- 반복자는 컨테이너 내부의 원소를 가리키고 접근할 수 있어야 한다.
- 반복자는 다음 원소로 이동하고 컨테이너의 모든 원소를 순회할 수 있어야 한다. 

- 반복자를 통해 알고리즘은 컨테이너에 종속적이지 않고도 컨테이너와 결합하여 동작할 수 있다. 
- STL의 모든 컨테이너는 자신만의 반복자를 제공한다. 
- [ begin, end ) | end는 끝의 다음 칸을 가리킨다.


### Adaptor

- container adaptor
	- stack, queue, priority_queue
- iterator adaptor
	- reverse_iterator, back_insert_iterator, front_insert_iterator, insert_iterator
- function adaptor
	- binder, negator, adaptor for pointers to functions


### allocator
- 컨테이너의 메모리 할당 정보와 정책을 캡슐화한 STL 구성 요소
- 템플릿 클래스 
- 모든 컨테이너는 템플릿 매개변수에 할당기를 인자로 받는다. 
- 기본 할당기는 allocator<T>
- 사용자가 직접 메모리 할당 방식을 제어할 수 있게 한다. 
- 사용자가 컨테이너에 맞는 메모리 할당 모델을 필요로 하거나 특정 구현 환경에 최적화된 메모리 할당기를 필요로 할때 커스텀해서 쓸 수 있다.

- 표준 컨테이너에서 필요로 하는 rebind라는 중첩(nested) 구조체 템플릿을 반드시 제공해야 한다.
  (출처 : http://egloos.zum.com/sweeper/v/2966785)

- allocator에 대해 정리가 잘된 블로그
  https://uncertainty-momo.tistory.com/53 