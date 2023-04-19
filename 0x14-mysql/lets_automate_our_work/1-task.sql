-- lets set up a user for mysql
-- This script should be run on both servers

CREATE USER IF NOT EXISTS 'holberton_user'@'localhost' IDENTIFIED BY 'projectcorrection280hbtn';
GRANT REPLICATION CLIENT ON * . * TO 'holberton_user'@'localhost';
