CREATE DATABASE  IF NOT EXISTS `projetointegrador` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `projetointegrador`;
-- MySQL dump 10.13  Distrib 8.0.22, for Win64 (x86_64)
--
-- Host: localhost    Database: projetointegrador
-- ------------------------------------------------------
-- Server version	8.0.22

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `losed`
--

DROP TABLE IF EXISTS `losed`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `losed` (
  `username` varchar(20) NOT NULL,
  `loseLv1` int DEFAULT NULL,
  `loseLv2` int DEFAULT NULL,
  `loseLv3` int DEFAULT NULL,
  `loseLv4` int DEFAULT NULL,
  `loseLv5` int DEFAULT NULL,
  `loseLv6` int DEFAULT NULL,
  `loseLv7` int DEFAULT NULL,
  `loseLv8` int DEFAULT NULL,
  `loseLv9` int DEFAULT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `max_score`
--

DROP TABLE IF EXISTS `max_score`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `max_score` (
  `username` varchar(20) NOT NULL,
  `maxScore_Lv1` int DEFAULT NULL,
  `maxScore_Lv2` int DEFAULT NULL,
  `maxScore_Lv3` int DEFAULT NULL,
  `maxScore_Lv4` int DEFAULT NULL,
  `maxScore_Lv5` int DEFAULT NULL,
  `maxScore_Lv6` int DEFAULT NULL,
  `maxScore_Lv7` int DEFAULT NULL,
  `maxScore_Lv8` int DEFAULT NULL,
  `maxScore_Lv9` int DEFAULT NULL,
  `maxScore_survival` int DEFAULT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `stats`
--

DROP TABLE IF EXISTS `stats`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `stats` (
  `sample_Mean` float DEFAULT NULL,
  `median` float DEFAULT NULL,
  `variance` float DEFAULT NULL,
  `standard_Deviation` float DEFAULT NULL,
  `Confidence_Interval` varchar(20) DEFAULT NULL,
  `username` varchar(20) NOT NULL,
  `proportion` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `users` (
  `login` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL,
  `played_survival` int DEFAULT NULL,
  `played_campaign` int DEFAULT NULL,
  `Lv1_Clear` int DEFAULT NULL,
  `Lv2_Clear` int DEFAULT NULL,
  `Lv3_Clear` int DEFAULT NULL,
  `Lv4_Clear` int DEFAULT NULL,
  `Lv5_Clear` int DEFAULT NULL,
  `Lv6_Clear` int DEFAULT NULL,
  `Lv7_Clear` int DEFAULT NULL,
  `Lv8_Clear` int DEFAULT NULL,
  `Lv9_Clear` int DEFAULT NULL,
  `email` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping events for database 'projetointegrador'
--

--
-- Dumping routines for database 'projetointegrador'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-11-03 15:12:28
