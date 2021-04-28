# AVL Trees

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-avl-tree/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-avl-tree/actions/workflows/cmake.yml)


_Краткое описание семестрового проекта._

- _В проекте реализуется структура данных AVL Tree_
- _AVL Tree - это сбалансированное двоичное дерево поиска_
- _Эта структура данных применяется в:_
  - _Шахматных программах_
  - _Системах поиска информации (в том числе операции get и set)_
  - _Организации таблиц_
  - _Сортировке данных_
- _Операции, реализуемые в AVL Tree:_
  - _Поиск вершины_
  - _Вставка вершины_
  - _Удаление вершины_
- _Теоретическая сложность по времени всех операций - `O(log n)`_
- Высота AVL Tree логарифмически зависит от количества вершин дерева 

## Команда "Lost in space"

**Примечание**. Преподаватель может определить вклад любого из участников команды по истории коммитов.

| Фамилия Имя   | Вклад (%) | Прозвище              |
| :---          |   ---:    |  ---:                 |
| Зиатдинов Марсель   | 100        |  -               |
| Беляева Мария   | 0        |  - |
| Бариева Миляуша   | 0        |  -         |

**Девиз команды**
> Такова жизнь

## Структура проекта

_Описание основных частей семестрового проекта._

Проект состоит из следующих частей:

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

Рекомендуемые требования:

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Интерпретатор _Python_ (версия _3.7.x_ и выше).
4. Рекомендуемый объем оперативной памяти - не менее 4 ГБ.
5. Свободное дисковое пространство объемом ~ 4 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

_Инструкция по сборке проекта, генерации тестовых данных, запуска контрольных тестов и примеров работы._

_Постарайтесь написать инструкцию так, чтобы незнакомый с проектом человек смог самостоятельно всё запустить._

### Windows

#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-avl-tree.git
```

Для ручной сборки проекта в терминале введите:

```shell
# переход в папку с проектом
cd C:\Users\username\asd-projects\semester-work-avl-tree

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```

#### Генерация тестовых данных

Генерация тестового набора данных в
формате [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values):

```shell
# переход в папку генерации набора данных
cd dataset

# запуск Python-скрипта
python generate_csv_bench_dataset.py
```
Нужно самому вставлять нужную фунцию между  auto time_point_before = chrono::steady_clock::now(); и auto time_point_after = chrono::steady_clock::now();
Также не забудьте сначала добавить элементы, если тестируете поиск или удаление элементов. В жизни не всё легко =(

Генерируется 10 наборов данных в каждом из них 14 наборов элементов с количеством от 100 до 5 000 000

```shell
dataset/data/
    01/
      100.csv
      ...
      5000000.csv
    02/ ...
    03/ ...
    ...
    10/ ...
  ...
```

Тестовые данные представлены в CSV формате (см.
[`dataset/data/`](dataset/data/)):

#### Контрольные тесты (benchmarks)

Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных.
Готовый набор данных [тут](https://drive.google.com/drive/folders/1X9auTKFMrrTgqOWRmLaYIPguVJDTEtD9)

##### Список контрольных тестов

|Название                  | Описание    | Метрики         |
| :---          |   ---:    |  ---:                 |
|benchmark      | Нужно вручную настраивать тестируемую функцию | нс (наносекунды)
 

## Источники

- https://en.wikipedia.org/wiki/AVL_tree
- https://medium.com/@dimko1/структуры-даных-avl-дерево-7f8739e8faf9
- https://visualgo.net/ru/bst
- https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

