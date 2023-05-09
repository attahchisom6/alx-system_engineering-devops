#!/usr/bin/python3
"""
gets the hottest top ten title in a querry
"""
import requests


def top_ten(subreddit):
    """function to get the top ten hottest title
    """
    url = "https://www.reddit.com/r/{}/about.json".format(subreddit)
    headers = {"User-Agent": "Mozilla/5.0"}

    response = requests.get(url, headers=headers, allow_redirects=False)
    if response.status_code == 200:
        j_response = response.json().get('data')
        for post in j_response.get('children')[:10]:
            return post.get('data').get('title')
    return None
