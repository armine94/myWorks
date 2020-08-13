-- MySQL dump 10.13  Distrib 5.7.30, for Linux (x86_64)
--
-- Host: localhost    Database: Projects
-- ------------------------------------------------------
-- Server version	5.7.30-0ubuntu0.18.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `departments`
--

DROP TABLE IF EXISTS `departments`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `departments` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `department` varchar(70) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`),
  UNIQUE KEY `department` (`department`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `departments`
--

LOCK TABLES `departments` WRITE;
/*!40000 ALTER TABLE `departments` DISABLE KEYS */;
INSERT INTO `departments` VALUES (3,'Bookkeeping'),(2,'Programing'),(1,'Testing');
/*!40000 ALTER TABLE `departments` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee_projects`
--

DROP TABLE IF EXISTS `employee_projects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `employee_projects` (
  `project_id` int(11) NOT NULL,
  `employee_id` int(11) NOT NULL,
  `workDate` date DEFAULT NULL,
  `workHours` int(11) DEFAULT NULL,
  KEY `project_id` (`project_id`),
  KEY `employee_id` (`employee_id`),
  CONSTRAINT `employee_projects_ibfk_1` FOREIGN KEY (`project_id`) REFERENCES `projects` (`id`),
  CONSTRAINT `employee_projects_ibfk_2` FOREIGN KEY (`employee_id`) REFERENCES `employees` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee_projects`
--

LOCK TABLES `employee_projects` WRITE;
/*!40000 ALTER TABLE `employee_projects` DISABLE KEYS */;
INSERT INTO `employee_projects` VALUES (1,2,'2020-01-09',5),(1,2,'2020-01-08',4),(1,2,'2020-01-10',6),(1,2,'2020-01-11',5),(1,2,'2020-01-12',4),(1,2,'2020-01-13',3),(1,3,'2020-01-08',4),(1,3,'2020-01-09',6),(1,3,'2020-01-10',5),(1,3,'2020-01-11',5),(1,2,'2020-01-14',4),(1,1,'2020-01-13',5),(1,1,'2020-01-14',4),(1,4,'2020-01-13',2),(1,4,'2020-01-14',3),(2,2,'2020-02-02',4),(2,2,'2020-02-03',5),(2,2,'2020-02-04',6),(2,2,'2020-02-07',5),(2,2,'2020-02-08',4),(2,2,'2020-02-09',5),(2,3,'2020-02-02',4),(2,3,'2020-02-04',6),(2,3,'2020-02-05',5),(2,3,'2020-02-07',5),(2,3,'2020-02-08',4),(2,3,'2020-02-09',6),(2,1,'2020-02-08',4),(2,1,'2020-02-09',4),(2,4,'2020-02-08',5),(2,4,'2020-02-09',3);
/*!40000 ALTER TABLE `employee_projects` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employees`
--

DROP TABLE IF EXISTS `employees`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `employees` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(30) NOT NULL,
  `surname` varchar(40) NOT NULL,
  `dateOfBirth` date DEFAULT NULL,
  `phone` varchar(30) NOT NULL,
  `hireDate` date NOT NULL,
  `department_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`),
  KEY `department_id` (`department_id`),
  CONSTRAINT `employees_ibfk_1` FOREIGN KEY (`department_id`) REFERENCES `departments` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employees`
--

LOCK TABLES `employees` WRITE;
/*!40000 ALTER TABLE `employees` DISABLE KEYS */;
INSERT INTO `employees` VALUES (1,'Ani','Asatryan','1994-05-06','37495667485','2015-05-05',1),(2,'Karine','Davtyan','1998-10-15','37444484142','2019-01-09',2),(3,'Gayane','Hovsepyan','1994-04-29','37493241173','2018-05-01',2),(4,'Narine','Voskanyan','1996-12-23','37498524536','2018-05-06',3);
/*!40000 ALTER TABLE `employees` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `projects`
--

DROP TABLE IF EXISTS `projects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `projects` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(70) NOT NULL,
  `startDate` date NOT NULL,
  `complete` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `projects`
--

LOCK TABLES `projects` WRITE;
/*!40000 ALTER TABLE `projects` DISABLE KEYS */;
INSERT INTO `projects` VALUES (1,'Online_Market','2020-01-08',1),(2,'Rugassko','2019-10-01',0),(3,'Asset_Manager','2020-02-01',0);
/*!40000 ALTER TABLE `projects` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-07-31 11:40:53
