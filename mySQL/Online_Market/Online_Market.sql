-- MySQL dump 10.13  Distrib 5.7.30, for Linux (x86_64)
--
-- Host: localhost    Database: new_Online_Market
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
-- Table structure for table `Costumers`
--

DROP TABLE IF EXISTS `Costumers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Costumers` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(35) NOT NULL,
  `city` varchar(35) NOT NULL,
  `street` varchar(50) NOT NULL,
  `phone` varchar(35) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=37 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Costumers`
--

LOCK TABLES `Costumers` WRITE;
/*!40000 ALTER TABLE `Costumers` DISABLE KEYS */;
INSERT INTO `Costumers` VALUES (1,'Karine','Vanadzor','Bazum','37498526247'),(2,'Gayane','Gyumri','Dimac','37494223344'),(3,'Hrant','Spitak','Sari_tax','37477854199'),(5,'Anna','Ararat','Erebuni','05566447788'),(6,'Vanna','Aparan','Kentron','885556699'),(8,'VVVVVanna','Aparan','Kentron','885556699'),(9,'A66666AAAnna','Ararat','Erebuni','05566447788'),(10,'VVVVVa55555nna','Aparan','Kentron','885556699'),(11,'A66666AAAnna','Ararat','Erebuni','05566447788'),(12,'VVVVVa55555nna','Aparan','Kentron','885556699'),(13,'GArik','abovyan','Xachatur','6545645645'),(14,'GArik','abovyan','Xachatur','6545645645'),(15,'GArik','abovyan','Xachatur','6545645645'),(16,'aa','abovyan','Xachatur','6545645645'),(17,'Serine','Abovyan','Arajin_Poxoc','37455887744'),(18,'Gayane','Aparan','Kentron','37444556699'),(19,'Mariam','EREVAN','Masiv_2','37498747576'),(20,'ANUSH','EREVAN','AVAN','37493554411'),(21,'aa','Abovyan','Arajin_Poxoc','37455887744'),(22,'aa','Aparan','Kentron','37444556699'),(23,'aa','EREVAN','Masiv_2','37498747576'),(24,'ANUSH','EREVAN','AVAN','37493554411'),(25,'aa','Abovyan','Arajin_Poxoc','37455887744'),(26,'TRIGGER','Aparan','Kentron','37444556699'),(27,'aa','EREVAN','Masiv_2','37498747576'),(28,'TRIGGER','EREVAN','AVAN','37493554411'),(29,'Serine','Abovyan','Arajin_Poxoc','37455887744'),(30,'Gayane','Aparan','Kentron','37444556699'),(31,'Mariam','EREVAN','Masiv_2','37498747576'),(32,'TRIGGER','EREVAN','AVAN','37493554411'),(33,'Serine','Abovyan','Arajin_Poxoc','37455887744'),(34,'Gayane','Aparan','Kentron','37444556699'),(35,'TRIGGER','EREVAN','Masiv_2','37498747576'),(36,'ANUSH','EREVAN','AVAN','37493554411');
/*!40000 ALTER TABLE `Costumers` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER triggerBeforeInsert
BEFORE INSERT
ON Costumers
FOR EACH ROW
BEGIN
IF @tmp = 2 THEN
SET @tmp = 0;
SET new.name = "TRIGGER";
SET @loop = @loop + 1;
ELSE
SET  @tmp = @tmp + 1;
SET @loop = @loop + 1;
END IF;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `OrderLines`
--

DROP TABLE IF EXISTS `OrderLines`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `OrderLines` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `product_id` int(11) NOT NULL,
  `order_id` int(11) NOT NULL,
  `productQuantity` int(11) NOT NULL,
  `productDelivired` tinyint(1) NOT NULL,
  `productDeliviredDate` date NOT NULL,
  `productDeliviredTime` datetime NOT NULL,
  PRIMARY KEY (`id`),
  KEY `product_id` (`product_id`),
  KEY `order_id` (`order_id`),
  CONSTRAINT `OrderLines_ibfk_1` FOREIGN KEY (`product_id`) REFERENCES `Products` (`id`),
  CONSTRAINT `OrderLines_ibfk_2` FOREIGN KEY (`order_id`) REFERENCES `Orders` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `OrderLines`
--

LOCK TABLES `OrderLines` WRITE;
/*!40000 ALTER TABLE `OrderLines` DISABLE KEYS */;
INSERT INTO `OrderLines` VALUES (2,1,5,5,0,'2020-04-06','2020-04-06 22:05:16'),(3,2,5,11,0,'2020-04-06','2020-04-06 22:05:16'),(4,2,6,5,1,'2020-04-06','2020-04-06 22:05:16'),(5,3,7,5,1,'2020-04-06','2020-04-06 22:05:16'),(6,3,7,5,0,'2020-04-06','2020-04-06 22:05:16'),(7,2,6,5,1,'2020-04-06','2020-04-06 22:05:16');
/*!40000 ALTER TABLE `OrderLines` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Orders`
--

DROP TABLE IF EXISTS `Orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Orders` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `costumer_id` int(11) NOT NULL,
  `orderPlacedDate` date NOT NULL,
  `orderPlacedTime` datetime NOT NULL,
  `orderCompleted` tinyint(1) NOT NULL,
  `orderCompletedDate` date NOT NULL,
  `orderComplitedTime` datetime NOT NULL,
  PRIMARY KEY (`id`),
  KEY `costumer_id` (`costumer_id`),
  CONSTRAINT `Orders_ibfk_1` FOREIGN KEY (`costumer_id`) REFERENCES `Costumers` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Orders`
--

LOCK TABLES `Orders` WRITE;
/*!40000 ALTER TABLE `Orders` DISABLE KEYS */;
INSERT INTO `Orders` VALUES (5,1,'2020-04-25','2020-04-25 16:25:08',1,'2020-04-26','2020-04-26 14:25:46'),(6,2,'2020-04-25','2020-04-25 16:25:08',1,'2020-04-26','2020-04-26 14:25:46'),(7,3,'2020-04-25','2020-04-25 16:25:08',1,'2020-04-26','2020-04-26 14:25:46');
/*!40000 ALTER TABLE `Orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Products`
--

DROP TABLE IF EXISTS `Products`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Products` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(35) NOT NULL,
  `pricePurchase` int(11) NOT NULL,
  `priceSale` int(11) NOT NULL,
  `stock` int(11) NOT NULL,
  `suppliert_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `suppliert_id` (`suppliert_id`),
  CONSTRAINT `Products_ibfk_1` FOREIGN KEY (`suppliert_id`) REFERENCES `Supplierts` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Products`
--

LOCK TABLES `Products` WRITE;
/*!40000 ALTER TABLE `Products` DISABLE KEYS */;
INSERT INTO `Products` VALUES (1,'Table',25000,32000,36,1),(2,'Door',37000,43000,57,2),(3,'Cup',500,700,157,3),(4,'Phone',44000,480000,65,4),(5,'Clock',12500,17800,120,4),(6,'Lack',2000,2500,0,2);
/*!40000 ALTER TABLE `Products` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Supplierts`
--

DROP TABLE IF EXISTS `Supplierts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Supplierts` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(35) NOT NULL,
  `city` varchar(35) NOT NULL,
  `street` varchar(50) NOT NULL,
  `phone` varchar(35) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Supplierts`
--

LOCK TABLES `Supplierts` WRITE;
/*!40000 ALTER TABLE `Supplierts` DISABLE KEYS */;
INSERT INTO `Supplierts` VALUES (1,'Garik','Gyumri','Dimac','374885544'),(2,'Arman','Vanadzor','3rd mas','37477441596'),(3,'Gor','Vanadzor','Bazum','37455000201'),(4,'Mihran','Erevan','Ajapnyak','37477845461');
/*!40000 ALTER TABLE `Supplierts` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-07-31  2:33:20
