#!/usr/bin/python3
"""
A program to query redit api for its subreddits
"""
import requests


def number_of_subscribers(subreddit):
    """
    gets the subreddit of a reddit api
    """
    url = "https://www.reddit.com/r/{}/about.json".format(subreddit)
    headers = {'User-Agent': 'Mozilla/5.0'}

    response = requests.get(url, headers=headers, allow_redirects=False)
    if response.status_code == 200:
        j_response = response.json().get('data')
        return j_response['subscribers']
    return 0
