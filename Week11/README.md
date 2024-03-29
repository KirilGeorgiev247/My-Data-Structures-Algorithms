# Task 01

Тази година всички студенти ще празнуват в Банско. За целта е необходима голяма транспортна организация, тъй като много хора ще пътуват от родните си места. Организирани са много автобуси, но за някои студенти като Васко, които тръгват от село, се налага да прикачват няколко автобуса, за да стигнат до Банско. Търсим най-краткото време, за което Васко ще стигне от стартовата спирка в селото му 's' до спирката на хотела му в Банско 'e'. Дадени са 'V' на брой спирки, 'E' на брой пътя между спирките. На всяка спирка си има точен интервал от време 'T_i', през който тръгва автобус от нея. Ако интервалът на дадена спирка е 4, то автобусът ще тръгва следните моменти от времето: 0, 4, 8, 12, ....

## Input Format

На първия ред са зададени 4 цели числа 'V', 'E', 's', 'e', където 'V' е броят на спирките, а 'E' е броят на пътищата между спирките. На втория ред са зададени 'V' на брой цели числа, които определят интервала, през който идва автобус на съответната спирка. На следващите 'E' на брой реда има по 3 числа: от коя до коя спирка има автобусна линия и необходимото разстояние 'W' за достигане до нея. От една спирка до друга може да има повече от един път.

## Constraints

```
1 ≤ V ≤ 10^4
1 ≤ E ≤ 10^5
1 ≤ T_i, W ≤ 10^3
```

## Output Format

На изхода изведете 1 число, най-краткото време, за което Васко ще стигне от стартовата спирка в селото му 's' до спирката на хотела му в Банско 'e'. Ако не съществува такъв път, изведете -1.

## Sample Input 0

```
5 6 0 3
4 5 12 10 20
0 1 10
0 4 3
1 2 8
2 3 6
4 2 7
4 3 18
```

## Sample Output 0

```
30
```

## Explanation 0

Имаме пет на брой спирки. През спирка 0 минава автобус на всеки 4 минути, на спирка номер 1 минава на всеки 5 минути, на спирка номер 2 на всеки 12 минути, спирка 3 - на всеки 10 минути, на спирка 4 - на всеки 20 минути.

Стартовата спирка е номер 0, а крайната номер 3.

Най-краткият път е 0->1->2->3.

Тръгваме във време 0 от спирка 0 и пътуваме до спирка 1 за 10 минути. След това тръгваме веднага във време 10 (без да чакаме) от спирка 1 към спирка 2. На спирка 2 стигаме във време 18 и чакаме 6 минути, защото там минава автобус на всеки 12 минути. Следователно тръгваме във време 24 от спирка 2 и стигаме спирка номер 3 на 30-тата минута.

***

#Task 02

Ели беше отвлечена! За щастие, тя намери плана на имението, в което бива държана като заложник. За нещастие, тя не знае къде точно в него се намира, тъй като беше със завързани очи, докато я вкарваха вътре.

За простота ще считаме имението като матрица с 'N' реда и 'M' колони. Всяка клетка може или да бъде празна (коридор) или блокирана (стена). В началото Ели се намира в някоя от празните клетки, но не знаем в коя от тях точно.

Ели може да се движи в четирите основни посоки – наляво, надясно, нагоре и надолу. Придвижването в съседна празна клетка не отнема време (все пак, трябва просто да се направят няколко крачки). Придвижването в блокирана клетка, обаче, отнема малко повече време – тя първо трябва да разбие стената там. Това отнема по един час на клетка. Считаме, че момичето е избягало от имението, когато достигне до неговия край – тоест до която и да е от крайните клетки на матрицата.

Ели вярва, че е затворена в някоя от празните клетки, от която ще ѝ отнеме най-много възможно време за да избяга. Тя ви е дала карта на имението под формата на матрица с 'N' реда и 'M' колони, всяка клетка от която е или '.' (коридор) или '#' (стена). Помогнете ѝ, като намерите броя на клетките, в които има възможност да се намира тя.

## Input Format

На първия ред на стандартния вход ще съдържа две цели числа 'N' и 'M' – съответно броя редове и броя колони на картата. Следват 'N' реда, всеки съдържащ по 'M' символа от азбуката {'.', '#'}.

## Constraints

```
1 ≤ N, M ≤ 1000
```

## Output Format

На стандартния изход изведете едно цяло число – броя клетки, от които би се излязло с най-много време дори при избор на оптималния път.

## Sample Input 0

```
7 14
.#............
.#####........
.#.#..#.......
.##.#.#.......
.#.#..#..####.
.#...##..#.##.
..####...###..
```

## Sample Output 0

```
1
```

## Sample Input 1

```
3 3
..#
...
.#.
```

## Sample Output 1

```
7
```

***

# Task 03

Всеобща заблуда е, че Дядо Коледа се придвижва чрез летяща шейна. За да не бъде забелязан, той всъщност се придвижва чрез мрежа от еднопосочни подземни тунели, като използва известното приложение - tunnel maps, за да се ориентира. Въпросната мрежа се състои от 'N' кръстовища, свързани помежду си с 'M' тунела.

Сега Дядо Коледа планира как ще стигне до къщата на Иван, за да му занесе дългоочаквания подарък. Проблемът е, че той не може да обикаля из тунелите твърде дълго, защото ще му падне батерията на телефона и ще се изгуби. Другият проблем на Дядо Коледа е, че както всички знаят, той не е много елегантен и ще му е невъзможно да мине през някои от по-тесните тунели. Планът му е да тръгне от кръстовище с номер 1, а къщата на Иван се намира на кръстовище с номер 'N'.

Помогнете на Дядо Коледа, като му кажете колко най-малко трябва да отслабне, за да може да стигне до къщата на Иван преди да му падне батерията на телефона, ако знаете колко време отнема да се премине през всеки от тунелите и с колко килограма трябва да отслабне Дядо Коледа, за може да мине през него.

## Input Format

От първият ред се въвеждат 'N', 'M' и 'K' - броят кръстовища, броят тунели и времето което издържа батерията на телефона.

От следващите 'M' реда се въвеждат по 4 числа: 'u', 'v', 'c' и 't' - съответно двете кръстовищата, които са свързани от тунела, килограмите които Дядо Коледа трябва да свали, за да може да премине и времето, което отнема да бъде преминат тунела.

## Constraints

```
1 ≤ N ≤ 10^5
1 ≤ M ≤ 3 × 10^5
1 ≤ u, v ≤ N
1 ≤ c, t, K ≤ 10^6
```

## Output Format

Изведете едно число - колко най-малко килограма трябва да отслабне Дядо Коледа, за да може да стигне до къщата на Иван. Ако не може да стигне за необходимото време, изведете -1.

## Sample Input 0

```
7 11 42
1 3 7 11
3 1 7 13
1 2 3 3
1 4 13 1
6 1 14 8
4 6 1 7
2 4 1 13
2 6 4 20
3 5 2 5
5 6 6 4
6 7 5 20
```

## Sample Output 0

```
7
```

## Explanation 0

Оптималният път е 1-3-5-6-7: Дядо Коледа трябва да свали 7кг и ще го измине за 40 минути.

## Sample Input 1

```
2 2 3
1 2 3 5
1 2 1 9
```

## Sample Output 1

```
-1
```
