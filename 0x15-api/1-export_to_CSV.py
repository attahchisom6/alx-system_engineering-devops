#!/usr/bin/python3
"""
API: a script to use an api to generate all record owned by
employee
"""
from sys import argv
from requests import get


if __name__ == "__main__":
    source = "https://jsonplaceholder.typicode.com"
    url = "{}/users".format(source)
    emp_id = argv[1]

    response = get("{}/{}".format(url, emp_id))
    empUsername = response.json().get("username")

    todo_url = "{}/{}/todos".format(url, emp_id)
    works = get(todo_url).json()

    with open("{}.csv".format(emp_id), mode="w") as f:
        for work in works:
            f.write('"{}","{}","{}","{}"\n'.format(
                emp_id, empUsername, work.get("completed"), work.get("title")))
