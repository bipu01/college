
data = {
    "user": "bozo",
    "psw": 1234
}

print(data["user"])

data["user"]= "biplove"
data["id"] = "124gqwrt"
del data['psw']


print(data)
print(data.keys())
print(data.values())

# tuple example
tuple_data = ("ram", "shyam", 123, 532 )

# new dict
food = {
    "cola": 3.2,
    "fanta": 12.2,
    "pepsi": 9.4,
    "burger": 3.4,
}

cost = 0
for key, value in food.items():
    cost += value
    print(f"current total cost: {cost}")


fruits = {
    "apple":0.32,
    "fanta":43.4
}

new_dict = {**food, **fruits}
print(new_dict)

values = (["x",'y','z'],[1,2,3],[True,False,True])

a, b, rest = zip(*values)

print(a)
print(b)
print(rest)


# set example
s1 = {1,2,1,4,5,2}
print(f's1:{s1}')

# remove duplicate items in list
list1 = [1,1,2,3,4,5,5,5,6,7,7,8]
list2 = set(list1)

print(f'list2:{list2}')




#
# if __name__ == "__main__":
#