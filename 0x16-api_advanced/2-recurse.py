#!/usr/bin/python3
"""
script to the host posts (latest) of subredit of a redit api
"""
import requests


def recurse(subreddit, hot_post=[], after="", count=0):
    """
    querries a subreddit and gets the number of times a word appears
    in the latest 100th post by recusion in each page of the api
    """
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "Mozilla/5.0"}
    response_control = {
            "after": after,
            "count": count,
            "limit": 100
            }

    response = requests.get(
            url, headers=headers, params=response_control,
            allow_redirects=False)
    if response.status_code != 404:
        j_response = response.json().get('data')
        after = j_response.get('after')
        count += j_response.get('dist')
        for post in j_response.get('children'):
            hot_post.append(post.get('data').get('title'))

        if after is not None:
            return recurse(subreddit, hot_post, after, count)
    return hot_post
