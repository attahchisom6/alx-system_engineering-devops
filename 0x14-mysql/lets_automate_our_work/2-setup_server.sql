-- setting up my replication server
-- This setup should be done in the master server
CREATE DATABASE IF NOT EXISTS tyrell_corp;
USE tyrell_corp;
CREATE TABLE IF NOT EXISTS nexus6 (id INT, name VARCHAR(256));
INSERT INTO nexus6 (id, name) VALUES (1, "John"), (2, "peter"), (3, "Paul");