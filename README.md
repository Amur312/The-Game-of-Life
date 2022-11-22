# The-Game-of-Life
Игра «Жизнь» (англ. Conway's Game of Life) — клеточный автомат, придуманный английским математиком Джоном Конвеем в 1970 году. 

Правила

Развитие колоний из трёх точек
Место действия игры — размеченная на клетки плоскость, которая может быть безграничной, ограниченной или замкнутой.
Каждая клетка на этой поверхности имеет восемь соседей, окружающих её, и может находиться в двух состояниях: быть «живой» (заполненной) или «мёртвой» (пустой).
Распределение живых клеток в начале игры называется первым поколением. Каждое следующее поколение рассчитывается на основе предыдущего по таким правилам:
в пустой (мёртвой) клетке, с которой соседствуют три живые клетки, зарождается жизнь;
если у живой клетки есть две или три живые соседки, то эта клетка продолжает жить; в противном случае (если живых соседей меньше двух или больше трёх) клетка умирает («от одиночества» или «от перенаселённости»).
Игра прекращается, если
на поле не останется ни одной «живой» клетки;
конфигурация на очередном шаге в точности (без сдвигов и поворотов) повторит себя же на одном из более ранних шагов (складывается периодическая конфигурация)
при очередном шаге ни одна из клеток не меняет своего состояния (предыдущее правило действует на один шаг назад, складывается стабильная конфигурация)
Игрок не принимает активного участия в игре. Он лишь расставляет или генерирует начальную конфигурацию «живых» клеток, которые затем изменяются согласно правилам. Несмотря на простоту правил, в игре может возникать огромное разнообразие форм.
![image](https://user-images.githubusercontent.com/86195238/203319670-fd026ddd-5ec7-4b82-adf1-fb3615ddf313.png)


Графика:

Поле — прямоугольник 80 на 25 клеток.
Подразумевается, что поле "замкнуто само на себя", к примеру у нижнего правого квадратика соседом справа является нижний левый квадратик, а соседом снизу - верхний правый.
Предусмотреть начальную инициализацию состояния "игры" через stdin. Подготовить как минимум 5 файлов с начальными состоянием для быстрого запуска и инициализации через перенаправление ввода.

Происхождение:
Джон Конвей заинтересовался проблемой, предложенной в 1940-х годах известным математиком Джоном фон Нейманом, который пытался создать гипотетическую машину, которая может воспроизводить сама себя. Джону фон Нейману удалось создать математическую модель такой машины с очень сложными правилами. Конвей попытался упростить идеи, предложенные Нейманом, и в конце концов ему удалось создать правила, которые стали правилами игры «Жизнь».

Впервые описание этой игры было опубликовано в октябрьском (1970 год) выпуске журнала Scientific American, в рубрике «Математические игры» Мартина Гарднера (Martin Gardner)[1].
