# Task 01

Градове, номерирани от 1 до N, са свързани с пътища. След като паднал сняг, останали проходими само M отсечки, всяка от които свързва два от градовете.

Ще получите Q на борй заявки от два вида:

- Въпрос относно възможно ли да се стигне от град a до град b

- Информация за това че отсечка свързваща град a и град b е почистена и вече е проходима.

Напишете програма, която отговарят на въпросите за актуалното състояние на пътищата.

## Input Format

На първия ред на стандартния вход ще бъдат зададени числата N и M. На всеки от следващите M реда – по два номера на град, свързани с проходима пътна отсечка.

Следва ред с броя Q на заявките и Q реда със съдържанието на заявките – вид на заявката и двата номера на населените места, за които се отнася съответното обаждане.

Ако заявката е въпрос – видът е 1, а ако е информация – видът е 2.

## Constraints

```
N ≤ 10^3
M ≤ 2 × N
Q ≤ 10^6
```

## Output Format

На стандартния изход програмата трябва да изведе битов низ с толкова знака, колкото са въпросите за проходимост на пътната мрежа, като знакът 0 означава че отговорът на поредния въпрос е "Невъзможно е да се стигне!", а знакът 1 – "Възможно е!".

## Sample Input 0

```
9 8
1 2
3 4
5 6
7 8
9 5
7 2
8 2
6 9
6
1 1 8
1 6 2
2 7 1
1 4 7
2 2 3
1 4 7
```

## Sample Output 0

```
1001
```

***

# Task 02

Имате дадени N града номерирани с чисалта от 1 до N и M двупосочни пътя, които ги свързват. Нито един от тези пътища все още не е простроен. Вие трябва да изберете N - 1 от тях, такива че е възможно да се достигне от всеки един град до всеки друг посредством тях. Освен това построяването на всеки път ви коства C1 усилие и ви носи C2 печалба за всяка единица усилие похарчена за построяването на пътя (цялостната печалба от построяването на един път е C1 * C2).

От вас се иска да намерите тези N - 1 пътя свързващи градовете, чието построяване ще ви коства минимално усилие. Ако има повече от една възможност, тогава искате да имате максимална печалба.

## Input Format

На първият ред от входа ще са ви дадени целите числа N и M.

Следват M реда с по 4 цели числа:

- ai, bi - номерата на върховете, които са свързани от поредния път

- C1i, C2i - усилието и печалбата за единица усилие за съответния път

## Constraints

```
1 ≤ N, M ≤ 2 x 10^5
1 ≤ ai, bi ≤ N
1 ≤ C1i < 10^17
-10^17 < C2i < 10^17
```

Aко има повече от едно решение, можете да отпечатате, което и да е от тях

## Output Format
	
Отпечатайте N - 1 реда, съдържащи индексите на пътищата които сте избрали да бъдат построени.

## Sample Input 0

```
3 3
1 2 1 7
2 3 3 2
1 3 2 3
```

## Sample Output 0

```
1
3
```

***

# Task 03

Знаете ли, че движението на автомобили с прекалено ниска скорост може също да затрудни движението и дори да доведе до пътно транспортно произшествие? За да се избегне това, наскоро беше решено да се въведе "минимална скорост" на движение по по-важните пътни артерии – тоест скорост, под която автомобилите не трябва да карат.

Оказва се, че дори по-добре е, когато автомобилите се движат с относително еднакви скорости. Затова сега управниците на държавата се чудят как да променят максималната и минималната скорост на движение, така, че разликата между тях да е минимална.

Всичко би било чудесно, ако пътищата в държавата бяха еднакви – тогава те биха могли просто да направят минималната скорост да е равна на максималната. За съжаление, това далеч не е така. Например нека сравним планински проход и автомагистрала, или пък път до произволно село и такъв до селото на някои от по-известните политици. Те имат доста различна препоръчителна скорост за движение, поради броя завои, теснотата, и нивото на поддръжката им.

За всеки от пътищата е направено изследване колко е "оптималната" скорост Si за движение по него. Ако политиците изберат максималната скорост да е под Fi или минималната да е над Ti, то пътят става неизползваем. Сега те се чудят какви да бъдат разрешените скорости, така че все пак да е възможно да се стигне от всяко населено място до всяко друго.

Input Format

На първия ред на стандартния вход ще бъдат зададени целите числа N и M – броя населени места и броя пътища.

Следват M на брой реда, всеки съдържащ по три цели числа Fi, Ti и Si, указващи, съответно, двупосочен път между Fi и Ti с оптимална скорост Si. Възможно е да има по повече от един директен път между две населени места.

Гарантирано е, че ще съществува път между всеки две населени места.

Constraints

```
2 ≤ N ≤ 1000
1 ≤ M ≤ 10000
1 ≤ Fi, Ti ≤ N
1 ≤ Si ≤ 30000
```

Output Format

На единствен ред на стандартния изход изведете две цели числа – минималната и максималната разрешена скорост, които хем са възможно най-близки, хем разрешават пътуването между всеки две населени места.

Ако съществува повече от един възможен отговор, изведете този с най-ниска минимална (а съответно и максимална) скорост.

Sample Input 0

```
7 10
1 3 2
4 2 8
1 2 11
1 4 3
1 3 6
5 3 5
3 6 9
7 6 6
5 6 3
2 5 7
```

Sample Output 0

```
3 7
```