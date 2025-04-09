# Yaroslav Kolesnik
class Person:
    def __init__(self, name, surname):
        self.name = name
        self.surname = surname

    def __str__(self):
        return 'name: {:10} surname: {:15}'.format(self.name, self.surname)


class Employee:
    def __init__(self, person, experience, salary):
        self.person = person
        self.experience = experience
        self.salary = salary

    def __str__(self):
        return '{} experience: {:2} salary: {:5}'.format(self.person,
                                                         self.experience, self.salary)


def selection_sort_for_personas(Company):
    for cur in range(len(Company)):
        min_person = cur
        for find_min in range(cur + 1, len(Company)):
            if Company[find_min].person.surname < Company[min_person].person.surname:
                min_person = find_min
            elif Company[find_min].person.surname == Company[min_person].person.surname:
                if Company[find_min].person.name < Company[min_person].person.name:
                    min_person = find_min
                elif Company[find_min].person.name == Company[min_person].person.name:
                    #SELECTION SORT NIE STABILNY
                    if Company[find_min].experience < Company[min_person].experience:
                        min_person = find_min
                    elif Company[find_min].experience == Company[min_person].experience:
                        if Company[find_min].salary < Company[min_person].salary:
                            min_person = find_min
        Company[cur], Company[min_person] = Company[min_person], Company[cur]

    return Company


def cocktail_sort_for_salaries(Company):
    swapped = True
    while swapped:
        swapped = False
        for search in range(0, len(Company) - 1):
            if Company[search].salary > Company[search + 1].salary:
                Company[search], Company[search+1] = Company[search+1],Company[search]
                swapped = True
        if not swapped:
            break
        swapped = False
        for search in range(len(Company) - 2, -1, -1):
            if Company[search].salary > Company[search + 1].salary:
                Company[search], Company[search+1] = Company[search+1],Company[search]
                swapped = True
    return Company


def count_sort_for_experiences(Company):
    maximum = Company[0].experience
    for i in range(len(Company)):
        if Company[i].experience > maximum:
            maximum = Company[i].experience
    count_array = [0] * (maximum + 1)
    for i in range(len(Company)):
        count_array[Company[i].experience] += 1
    to_add = 0
    for i in range(len(count_array)):
        count_array[i] += to_add
        to_add = count_array[i]
    output_array = [0] * len(Company)
    for i in range(len(Company) - 1, -1, -1):
        count_array[Company[i].experience] -= 1
        output_array[count_array[Company[i].experience]] = Company[i]
    return output_array


names = raw_input().split()
surnames = raw_input().split()
experiences = raw_input().split()
salaries = raw_input().split()
Company = []
if len(names) == len(surnames) == len(experiences) == len(salaries):
    for i in range(len(names)):
        Company.append(Employee(Person(names[i], surnames[i]), int(experiences[i]), int(salaries[i])))
    if Company:
        Company = cocktail_sort_for_salaries(Company)
        Company = count_sort_for_experiences(Company)
        Company = selection_sort_for_personas(Company)
        for i in Company:
            print(i)




'''
Adam Bromir Bruno Abelard Adam Bromir Bruno Abelard Adam Bromir Bruno Abelard Adam Bromir Bruno Abelard
Dachtera Dacka Dachtera Dacka Dachtera Dacka Dachtera Dacka Dachtera Dacka Dachtera Dacka Dachtera Dacka Dachtera Dacka
8 25 56 2 24 59 19 38 8 25 56 2 24 59 19 38
7080 4500 6360 3120 8040 10140 7740 8880 8640 3540 3180 3240 7500 7020 9840 7800
'''

