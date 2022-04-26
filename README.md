# ft_containers

Containers abstracting : 
- vector: Dynamic contiguous array
- list: Circular double linked list
- map: Binary Search Tree of key-value pairs, sorted by unique keys.
- stack: Adapts a container to provide stack (LIFO - Last In First Out)
- queue: Adapts a container to provide queue (FIFO - First In First Out)
- set are containers that store unique elements following a specific order.


## Set

### Member functions:

- [X] constructor by default (1)
- [X] constructor range (2)
- [X] constructor by copy (3)

- [X] ~set

- [X] operator=

-Iterators
- [X] begin
- [X] end
- [X] rbegin
- [X] rend

-Capacity
- [X] empty
- [X] size
- [X] max_size

-Modifiers
- [X] insert
- [X] erase
- [X] swap
- [X] clear

-Observers
- [X] key_comp
- [X] value_comp

-Operations
- [X] find
- [X] count
- [X] lower_bound
- [X] upper_bound
- [X] equal_range

-Allocator
- [X] get_allocator

### Non-member overloads:
- [X] relational operators
- [X] swap

https://www.cplusplus.com/reference/set/set/
## Map

Map
Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.

In a map, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to this key. The types of key and mapped value may differ, and are grouped together in member type value_type, which is a pair type combining both:

typedef pair<const Key T> value_type;

Containers abstracting : pointer to RBtree Nodes
Iterator type : bidirectional & reverse iterator

https://www.cplusplus.com/reference/map/map/

### Member functions:

- [X] constructor by default (1)
- [X] constructor with range (2)
- [X] constructor by copy (3)
- [X] destructor
- [X] operator=

-Iterators
- [X] begin
- [X] end
- [X] rbegin
- [X] rend

-Capacity
- [X] empty
- [X] size
- [X] max_size

-Element access
- [X] operator[]

-Modifiers
- [X] insert (1) single elemnt
- [X] insert (2) with hint
- [X] insert (3) range
- [X] erase (1) with iterator
- [X] erase (2)	with key
- [X] erase (3) with range
- [X] swap
- [X] clear

-Observers
- [X] key_comp
- [X] value_comp

-Operations
- [X] find
- [X] count
- [X] lower_bound
- [X] upper_bound
- [X] equal_range

-Allocator
- [X] get allocator

### Non-member overloads:
- [X] relational operators
- [X] swap
## Stack

Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container.

https://www.cplusplus.com/reference/stack/stack/

### member functions:

- [X] Constructors
- [X] Destructors
- [X] stack::empty()
- [X] stack::size()
- [X] stack::top()
- [X] stack::push()
- [X] stack::pop()

### non-member function overloads:

- [X] relational operators

## Vector

Containers abstracting : Dynamic contiguous array
Iterator type : Random acces & reverse iterator

https://www.cplusplus.com/reference/vector/vector/

### member functions:

Canonique form :

- [X] (1)vector::vector() (default)
- [X] (2)vector::vector(n, val) (fill)
- [X] (3)vector::vector(first, last) (range)
- [X] (4)vector::vector(vector const &) (copy)
- [X] vector::~vector()
- [X] vector::operator=

- [X] vector::assign(range)
- [X] vector::assign(fill)
- [X] vector::at
- [X] vector::back
- [X] vector::begin
- [X] vector::capacity
- [X] vector::clear
- [X] vector::empty
- [X] vector::end
- [X] vector::erase
- [X] vector::front
- [X] vector::get_allocator
- [X] vector::insert
- [X] vector::max_size
- [X] vector::operator[]
- [X] vector::pop_back
- [X] vector::push_back
- [X] vector::rbegin
- [X] vector::rend
- [X] vector::reserve
- [X] vector::resize
- [X] vector::size
- [X] vector::swap

### non-member overloads:

- [X] relational operators (vector)
	
	- [X] ==
	
	- [X] <
	
	- [X] != a!=b	-> !(a==b)
	
	- [X] <= a<=b	-> !(b < a)
							
	- [X] >	a>b	->  b < a
							 
	- [X] >= a>=b	->!(a < b)
							
- [X] swap (vector)


## useful sites for red black binary trees :

Arbres binaires simples : 	http://carl.seleborg.free.fr/cpp/cours/chap2/arbres.html
							https://cours.etsmtl.ca/SEG/FHenri/inf145/Suppl%C3%A9ments/arbres%20binaires.htm

Arbres binaires Rouges Noires:
	https://fr.wikipedia.org/wiki/Arbre_bicolore
	https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/
	https://miashs-www.u-ga.fr/prevert/Prog/Java/CoursJava/arbresRougeNoir.html

simulateurs: https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
							
## Runtime recovery with Ruby and |bc
```bash
start=$(ruby -e 'puts Time.now.to_f')
./my_process
end=$(ruby -e 'puts Time.now.to_f')
runTime=$(echo "$end - $start" | bc)

printf "Runtime = $runTime s\n"
```
