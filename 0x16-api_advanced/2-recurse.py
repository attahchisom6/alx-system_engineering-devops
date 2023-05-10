#!/usr/bin/python3
"""
script to the host posts (latest) of subredit of a redit api
"""
import requests


def count_post_byRecursion(subreddit, hot_post=[], after="", count=0):
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
            url, headers=headers, params=response_control, allow_redirects=False)
    if response.status_code == 200:
        j_response = response.json().get('data')
        titles = j_response.get('children')
        after = j_response.get('after')
        count += j_response.get('dist')
        for post in titles:
            hot_post.append(post.get('data').get('title'))

        if after is not None:
            return count_post_byRecursion(subreddit, hot_post, after, count)
        return hot_post
    return None
