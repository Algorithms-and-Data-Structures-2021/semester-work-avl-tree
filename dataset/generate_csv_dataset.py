import csv
import numpy
from threading import Thread
from datetime import datetime

MAX_VALUE = 1000000


def get_random_array(amount):
    return numpy.random.randint(0, MAX_VALUE, amount)


def save_to_csv(count, file_name: str):
    array = get_random_array(count//10)
    with open(file_name + ".csv", "a", newline="") as file:
        writer = csv.writer(file)
        writer.writerow(array)


if __name__ == "__main__":
    for key in ['01', '02', '03', '04', '05', '06', '07', '08', '09', '10']:
        for value in [100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 750000, 1000000, 2500000, 5000000]:
            time1 = datetime.now()

            thread = []
            for i in range(10):
                thread.append(Thread(target=save_to_csv, args=(value, 'data/{}/'.format(key) + str(value))))

            for i in range(10):
                thread[i].start()

            for i in range(10):
                thread[i].join()

            time2 = datetime.now()
            print(value, ': ', time2 - time1)
