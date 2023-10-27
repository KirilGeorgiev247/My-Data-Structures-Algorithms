# Task01 #

Given pointers to the heads of two sorted linked lists, merge them into a single, sorted linked list. Either head pointer may be null meaning that the corresponding list is empty.

Example

headA refers to 1 -> 3 -> 7 -> NULL

headB refers to 1 -> 2 -> NULL

The new list is 1 -> 1 -> 2 -> 3 -> 7 -> NULL

Function Description

Complete the mergeLists function in the editor below.

mergeLists has the following parameters:

SinglyLinkedListNode pointer headA: a reference to the head of a list

SinglyLinkedListNode pointer headB: a reference to the head of a list

Returns

SinglyLinkedListNode pointer: a reference to the head of the merged list

*---*

Input Format

The first line contains an integer t, the number of test cases.

The format for each test case is as follows:

The first line contains an integer n, the length of the first linked list.
The next n lines contain an integer each, the elements of the linked list.
The next line contains an integer m, the length of the second linked list.
The next m lines contain an integer each, the elements of the second linked list.

1

3

1

2

3

2

3

4

Sample Output

1 2 3 3 4 

Explanation

The first linked list is: 1 -> 3 -> 7 -> NULL

The second linked list is: 3 -> 4 -> NULL

Hence, the merged linked list is: 1 -> 2 -> 3 -> 3 -> 4 -> NULL

# Task02 #

You are given the pointer to the head node of a sorted linked list, where the data in the nodes is in ascending order. Delete nodes and return a sorted list with each distinct value in the original list. The given head pointer may be null indicating that the list is empty.

Example

head refers to the first node in the list 1 -> 2 -> 2 -> 3 -> 3 -> 3 -> 3 -> NULL

Remove 1 of the 2 data values and return head pointing to the revised list 1 -> 2 -> 3 -> NULL

Function Description

Complete the removeDuplicates function in the editor below.

removeDuplicates has the following parameter:

SinglyLinkedListNode pointer head: a reference to the head of the list
Returns

SinglyLinkedListNode pointer: a reference to the head of the revised list

*---*

Input Format

The first line contains an integer t, the number of test cases.

The format for each test case is as follows:

The first line contains an integer n, the number of elements in the linked list.
Each of the next n lines contains an integer, the data value for each of the elements of the linked list.

Sample Input

STDIN   Function
-----   --------
1       t = 1

5       n = 5

1       data values = 1, 2, 2, 3, 4

2

2

3

4

Sample Output

1 2 3 4 

Explanation

The initial linked list is: 1 -> 2 -> 2 -> 3 -> 4 -> NULL

The final linked list is: 1 -> 2 -> 3 -> 4 -> NULL

# Task03 #

Given the pointer to the head node of a linked list and an integer to insert at a certain position, create a new node with the given integer as its  attribute, insert this node at the desired position and return the head node.

A position of 0 indicates head, a position of 1 indicates one node away from the head and so on. The head pointer given may be null meaning that the initial list is empty.

Example

head refers to the first node in the list 1 -> 2 -> 3

data = 4

position = 2

Insert a node at position 2 with data = 4. The new list is 1 -> 2 -> 4 -> 3

Function Description: Complete the function insertNodeAtPosition in the editor below. It must return a reference to the head node of your finished list.

insertNodeAtPosition has the following parameters:

head: a SinglyLinkedListNode pointer to the head of the list

data: an integer value to insert as data in your new node

position: an integer position to insert the new node, zero based indexing

Returns

SinglyLinkedListNode pointer: a reference to the head of the revised list

*---*

Input Format

The first line contains an integer n, the number of elements in the linked list.
Each of the next  lines contains an integer SinglyLinkedListNode[i].data.
The next line contains an integer data, the data of the node that is to be inserted.
The last line contains an integer position.

Sample Input

3

16

13

7

1

2

Sample Output

16 13 1 7

Explanation

The initial linked list is 16 -> 13 -> 7. Insert 1 at the position 2 which currently has 7 in it. The updated linked list is 16 -> 13 -> 1 -> 7.

# Task04 #

На всеки от вас е позната концепцията за кеш памет - пазят се N на брой елементи, които са най-често изполвани. Когато правим заявка за търсене, първо се проверява дали елементът, който търсим, е в кеша, и чак ако не го намерим, търсим в паметта.

Реализирайте кеш памет, която да отговаря на следните заявки:

put <x> <y> - добавя елемент с ключ x и стойност y, ако го няма в кеша. Ако го има в кеша, обновява стойността му. И в двата случая това става най-скоро използваният елемент. Ако се опитаме да добавим елемент, когато капацитетът на кеш паметта е запълнен, изхвърляме от нея най-отдавна използвания елемент.

get <x> - отпечатва стойността на елемента с ключ x, ако го има в кеша. Отново става най-скоро използваният елемент. Ако го няма в кеша, отпечатва -1.

Вашата кеш памет за съжаление не е от най-мощните и от време на време прегрява. Това се случва след изпълнението на всяка K-та заявка. Когато прегрее, се изтрива най-отдавна използвания елемент.

*---*

Input Format

Първият ред на стандартния вход съдържа три цели числа - капацитета на кеш паметта - N, броя на заявките - Q и броя на заявки, след които прегрява - K. На следващите Q реда получавате заявки от типа put <x> <y> или get <x>.

Output Format

Трябва да изведете отговорите на всяка get заявка на нов ред.

Sample Input 0

2 9 4

put 1 1

put 2 2 

get 1

put 3 3 

get 2

put 4 4 

get 1

get 3

get 4

Sample Output 0

1

-1

-1

3

-1

Explanation 0

Капацитетът на кеш паметта е 2. Добавяме (1,1) и (2,2) и ключовете, записани в кеша, изглеждат така:

2 1

Търсим елемента с ключ 1 - намираме го и той става последният използван:

1 2

Добавяме (3,3), надхвърляме капацитета и изтриваме последния елемент:

3 1

Но това е 4тата заявка, така че изтриваме и (1,1):

3

Търсим 2 - не го намираме и връщаме -1. Добавяме (4,4):

4 3

Търсим 1, него го няма, 3 го намираме, но това отново е 4та заявка, затова изтриваме (4,4) и не го намираме.

# Task05 #

Митьо Пищова обича да прави пищови по време на контролните на Милен Ч++ в зала 210 на Химическия Факултет.

Обаче Пищова не е сам, колегите му стоящи отдясно по време на контролното постоянно го снабдяват с нови и нови пищови на тема Merge Sort, Binary Search и Counting Sort.

Милен Ч++ като един внимаващ квестор забелязва листчетата, но вместо да ги крие и да прави забележка на Митьо, той ги разбърква, за да може дори и когато Митьо преписва, да се потруди, пренареждайки отново пищовите си.

*---*

Input Format

На стандартния вход получавате цяло число N - брой заявки. На следващите N реда получавате заявки от вида:

add <x> - Митьо добавя пищов номер х

gun - Митьо преписва 1 пищов

milen - Милен Ч++ идва, вижда го и му пренарежда пищовите.

В началото Митьо не разполага с никакви средства за преписване.

При заяка add <x>, Митьо получава тема и я слага най-отдясно на вече текущо наредените теми под чина.

Например:

3

add 1

add 3

add 2

=> Като краен резултат под чина се получава: 1 3 2

При команда gun, Митьо преписва от най-десния елемент на редицата от пищови. Гарантирано е, че НЯМА ДА ПОЛУЧИТЕ КОМАНДА gun при 0 брой пищови. След команда gun, Митьо премахва и слага в джоба си най-дясното листче.

Пример:

4

add 3

add 2

add 4

gun

=> Крайната наредба става: 3 2 ( 4 се преписва успешно от Митьо )

Команда milen - Милен Ч++ идва и хваща първата половина ( ПРИ НЕЧЕТЕН БРОЙ ВЗЕМА С 1 ЕЛЕМЕНТ ПО-МАЛКО ОТ ЛЯВАТА ПОЛОВИНА ПРИ 5 елемента взема 2 от ляво ) от редицата от числа и я премества елементите един по един най-отдясно.

Пример:

5

add 1

add 2

add 3

add 4

milen

Крайна наредба: 3 4 1 2 ( Първоначално имате 1 2 3 4, Милен Ч++ идва и хваща 1 и 2 и ги слага един по един отдясно на 3 и 4 )

НЯМА ДА ПОЛУЧИТЕ gun при ПРАЗНА РЕДИЦА, НЯМА ДА ПОЛУЧИТЕ milen при ПРАЗНА РЕДИЦА. x в заявката add ще е <= N и няма да получите повтарящи x.

Output Format

Изход:

Броят пищови под чина на Митьо и на нов ред:

Крайната наредба на пищовите на Митьо след N-те заявки.

Sample Input 0

8

add 1

add 2

add 4

add 3

add 5

add 8

gun

milen

Sample Output 0

5

4 3 5 1 2

Sample Input 1

4

add 1

gun

add 2

gun

Sample Output 1

0

