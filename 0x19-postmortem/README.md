# **POST MORTEM: A SERVER BREAK DOWN INCIDENCE REPORT**
> WRITTEN BY ATTAH CHISOM MOSES

![](https://www.pexels.com/photo/doll-wearing-eyeglasses-160472/)

On may 14th 2023, we experienced a sever breakdown in one of our servers, so that the many of our clients using the api related to this server was unable to acsess it contents for their various purposes. We sincerely apologize to client who may have a financial loss or any other loss due to this incovinience.

## Issue Summary

On 14th may 2023 (12pm GMT +1) we experienced a server break down, in one of our master servers that runs on nginx. Our customers acessing this server experienced a _**502 Bad Gateway error**_. The root cause being pushing an application configured by a web framework to run on apache2. The result being that all services made to be handled by this application was rendered ineffective.

## IMPACT

The result of the above error was a 100% impact on our clients and their Buisnesses, as important information submitted by these clients on the server was not being delivered when requested.

## DETECTION AND DURATION OF THE ISSUE
The afore mentioned issue lasted for a period of 48 minutes (12:00 pm - 12: 48pm) GMT +1. The issue was first noticed at 12:10 pm on the recipient of alerts from the datadog community monitoring agent, followed by clients mail regarding the issue whereupon proper measuress were implemented to handle the issue

## ROOT CAUSES

The root cause is pushing an application made to run on apache2 to a server made to run on Nginx, with both of them , listening on the same port by default, resulting to a server breakdown

## MEASURES TAKEN TO ARREST THE ISSUE

1. Upon detection of the issue, we removed the defect application causing the issue. Then a roll back was made to restore the server to its previous setting at 12: 30 pm Gmt.

2. A test was run, and it was confirmef that every thing was back to Normal.

3. The defective app was then reconfigured to run on nginx, and tested thoroughly in several test servers before being deployed again to the master server

4. At 12:48 GMT +1 another test was run, but this time on the master server, and everything was confirmed to be working well as planned. Feedback from our clients also confirmed that the issue was fixed as they could now asses thier contents and can also make use of our new deployed application

## PREVENTIVE MEASURES

These are the preventive measures set to prevent a re-occurrrence of these ussues in the future.

1. Due to different reasons, each of our severs run on different kinds of web infrastructures like apache2 or nginx etc. its best that before any update were pushed to a server, a proper analysis of the server must be first observed and taking into account.

2. The application to be deployed must ne examined by teams in charge of the servers before deployment

3. If in the future an issue like this still occur, we are implementing a cross platfform where the clients will be redirected to another platform handled by a different unit, where their data can as well be accesed. This is made possible by infrastructures like but not limited to Master-slave server configurations
