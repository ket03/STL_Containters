# STL_Containters

Собственная реализация контейнеров для лучшего понимания принципов работы классов, контейнеров, итераторов, дианмической памяти

vector - динамический массив. Увеличивает свой размер и перевыделяет память.
1) Создается новый резервный массив длинной х2 от текущего
2) Данные со старого массива копируется в резервный
3) Исходный массив удаляется
4) Для исходного массива выделяется память х2 от старого размера
5) Данные с резервного копируются в исходный
6) Резервный удаляется

Stack сделан на основе vector. По сути тот же вектор, но обращаться можно только к последнему по индексу элементу.

Set - основан на автобалансирующем Красно-Черном Дереве.

List - не использует большие куски памяти. Использует хаотичное по месторасположению ячейки памяти и сохраняет адреса следующего и предыдущего элемента.