#!/usr/bin/python3
"""
gets the hottest top ten title in a querry
"""
import requests


def top_ten(subreddit):
    """function to get the top ten hottest title
    """
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "Mozilla/5.0"}

    response = requests.get(url, headers=headers, allow_redirects=False)
    if response.status_code == 200:
        j_response = response.json().get('data')

        ten_titles = j_response.get('children')[:10]
        for post in ten_titles:
            print(post.get('data').get('title'))
    else:
        print(None)
