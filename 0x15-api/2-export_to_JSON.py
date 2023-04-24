#!/usr/bin/python3
"""
API: a script to use an api to generate all record owned by
employee
"""
import json
from sys import argv
from requests import get


if __name__ == "__main__":
    source = "https://jsonplaceholder.typicode.com"
    url = "{}/users".format(source)
    emp_id = argv[1]

    response = get("{}/{}".format(url, emp_id))
    empUsername = response.json().get("username")

    todo_url = "{}/{}/todos".format(url, emp_id)
    tasks = get(todo_url).json()

    dictt = {emp_id: []}
    for task in tasks:
        dictt[emp_id].append({
            "task": task.get("title"),
            "completed": task.get("completed"),
            "username": empUsername
            })

    with open("{}.json".format(emp_id), mode="w") as f:
        json.dump(dictt, f)
