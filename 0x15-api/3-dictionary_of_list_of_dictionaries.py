#!/usr/bin/python3
"""API: python script to get a dictionary of list of dictionaries
"""
import json
from requests import get


if __name__ == "__main__":
    source = "https://jsonplaceholder.typicode.com"
    url = "{}/users".format(source)

    users = get(url).json()
    dictt = {}
    for response in users:
        userName = response.get("username")
        user_id = response.get("id")

        refined_url = "{}/{}".format(url, user_id)
        todo_url = "{}/todos/".format(refined_url)
        todo_response = get(todo_url)

        tasks = todo_response.json()
        dictt[user_id] = []
        for task in tasks:
            dictt[user_id].append({
                    "task": task.get("title"),
                    "completed": task.get("completed"),
                    "username": userName
                    })

    with open("todo_all_employees.json", mode="w") as f:
        json.dump(dictt, f)
