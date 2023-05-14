# **POST MORTEM: A SERVER BREAK DOWN INCIDENCE REPORT
> WRITTEN BY ATTAH CHISOM MOSES

![](https://https://twitter.com/i/status/834887829486399488)

On may 14th 2023, we experienced a sever breakdown in one of our servers, so that the many of our clients using the api related to this server was unable to acsess it contents for their various purposes. We sincerely apologize to client who may have a financial loss or any other loss due to this incovinience

## Issue Summary
On 14th may 2023 (12pm GMT +1) we experienced a server break down, in one of our master servers that runs on nginx. Our customers acessing this server experienced a _**502 Bad Gateway error**_. The root cause being pushing an application configured by a web framework to run on apache2. The result being that all services made to be handled by this application was rendered ineffective.

## IMPACT
The result of the above error was a 100% impact on our clients and their Buisnesses, as important information submitted by these clients on server was not being delivered when requested.

## DETECTION AND DURATION OF THE ISSUE
This afore mentioned issue lasted for a period of 48 minutes (12:00 pm - 12: 48pm) GMT +1. The issue was first noticed at 12:10 pm on the recipient of alerts from the datadog community monitoring agent, followed by clients mail regarding the issue whereupon proper measuress were implemented to handle the issue
