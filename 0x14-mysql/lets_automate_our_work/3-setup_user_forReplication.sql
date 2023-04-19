-- we will set up a user for our replication server and grant it a slave replication privilege
-- This script should be run on your master server

-- Notee: any password can do herw
CREATE USER IF NOT exists 'replica_user'@'%' IDENTIFIED BY 'web';
GRANT REPLICATION SLAVE ON * . * TO 'replica_user'@'%';
GRANT SELECT ON mysql . user TO 'holberton_user'@'localhost';
