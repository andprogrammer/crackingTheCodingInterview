from enum import Enum


class AnimalType(Enum):
    DOG = 1
    CAT = 2


class Animal(object):
    def __init__(self, animal_type, number):
        self.animal_type = animal_type
        self.number = number

    def __str__(self):
        return 'ANIMAL' + str(self.animal_type) + ' ' + str(self.number)


class AnimalShelter(object):
    def __init__(self):
        self.dogs = []
        self.cats = []

    def enqueue(self, animal):
        if animal.animal_type is AnimalType.DOG:
            self.dogs.append(animal)
        elif animal.animal_type is AnimalType.CAT:
            self.cats.append(animal)
        else:
            raise Exception('Not supported Animal Type')

    def dequeueAny(self):
        if self.dogs:
            tmp = self.dogs[-1]
            del self.dogs[-1]
            return tmp
        elif self.cats:
            tmp = self.cats[-1]
            del self.cats[-1]
            return tmp
        raise Exception('No dogs')

    def dequeueDog(self):
        if self.dogs:
            tmp = self.dogs[-1]
            self.dogs.remove(tmp)
            return tmp
        raise Exception('No dogs')

    def dequeueCat(self):
        if self.cats:
            tmp = self.cats[-1]
            del self.cats[-1]
            return tmp
        raise Exception('No cats')


if __name__ == '__main__':
    dog = Animal(AnimalType.DOG, 67)
    dog2 = Animal(AnimalType.DOG, 91)
    cat = Animal(AnimalType.CAT, 4)
    cat2 = Animal(AnimalType.CAT, 8)

    shelter = AnimalShelter()
    shelter.enqueue(dog)
    shelter.enqueue(dog2)
    shelter.enqueue(cat)
    shelter.enqueue(cat2)
    x = shelter.dequeueDog()
    print(x)
    print(shelter.dequeueDog())
    print(len(shelter.dogs))
