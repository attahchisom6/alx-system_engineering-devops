#!/usr/bin/python3
"""
A python script to use RESTful API to return information about a user
"""
import requests
from sys import argv


if __name__ == "__main__":
    emp_id = argv[1]
    source = "https://jsonplaceholder.typicode.com"

    url = "{}/users".format(source)
    response = requests.get("{}/{}".format(url, emp_id))
    empName = response.json().get("name")

    to_do_url = "{}/{}/todos".format(url, emp_id)
    todo_response = requests.get(to_do_url)
    works = todo_response.json()

    finished_works = []
    count = 0

    for work in works:
        if work.get("completed"):
            finished_works.append(work)
            count += 1

    print("Employee {} is done with tasks({}/{}):".format(
        empName, count, len(works)))
    for work in finished_works:
        print("\t {}".format(work.get("title")))
