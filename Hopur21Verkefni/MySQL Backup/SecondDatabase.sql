-- phpMyAdmin SQL Dump
-- version 4.6.5.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Dec 06, 2016 at 11:51 AM
-- Server version: 5.6.29-76.2
-- PHP Version: 5.6.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `harlausniris_computer_scientist`
--

-- --------------------------------------------------------

--
-- Table structure for table `computers`
--

CREATE TABLE `computers` (
  `ID` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `design_year` date DEFAULT NULL,
  `build_year` date DEFAULT NULL,
  `type_ID` int(11) NOT NULL,
  `is_created` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `computers`
--

INSERT INTO `computers` (`ID`, `name`, `design_year`, `build_year`, `type_ID`, `is_created`) VALUES
(4, 'The difference engine', '1831-01-01', '1991-01-01', 1, 1),
(5, 'Analytical Engine', '1837-01-01', '1991-01-01', 2, 1),
(6, 'Pascaline', '1642-01-01', '1652-01-01', 1, 1),
(7, 'The Thomas Arithmometer', '1820-01-01', '1820-01-01', 1, 1),
(8, 'Drift Sight', '1916-01-01', '1916-01-01', 15, 1),
(9, 'Z1', '1936-01-01', '1938-01-01', 16, 1),
(10, 'Z2', '1939-01-01', '1939-01-01', 17, 1),
(11, 'Z3', '1941-01-01', '1941-01-01', 18, 1),
(12, 'Atanasoff–Berry Computer (ABC)', '1942-01-01', '0000-01-01', 19, 0),
(13, 'Colossus', '1943-01-01', '1945-01-01', 20, 1),
(14, 'Colossus Mark 2', '1944-01-01', '1945-01-01', 20, 1),
(15, 'ENIAC', '1943-01-01', '1945-01-01', 20, 1),
(16, 'Enigma', '1918-01-01', '1918-01-01', 21, 1),
(17, 'Manchester baby', '1948-01-01', '1948-01-01', 22, 1);

-- --------------------------------------------------------

--
-- Table structure for table `computer_scientists`
--

CREATE TABLE `computer_scientists` (
  `ID` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `birth_year` date NOT NULL,
  `death_year` date DEFAULT NULL,
  `gender` varchar(255) NOT NULL,
  `comment` varchar(10000) DEFAULT NULL,
  `is_alive` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `computer_scientists`
--

INSERT INTO `computer_scientists` (`ID`, `name`, `birth_year`, `death_year`, `gender`, `comment`, `is_alive`) VALUES
(1, 'Charles Babbage', '1791-01-01', '1871-01-01', 'Male', 'He is best remembered for originating the concept of a programmable computer.', 0),
(2, 'Ada Lovelace', '1815-01-01', '1852-01-01', 'Female', 'Was an analyst of Charles Babbages analytical engine and considered by many the first computer programmer', 0),
(3, 'Blaise Pascal', '1623-01-01', '1662-01-01', 'Male', 'In 1642 while still a teenager he started some pioneering work on calculating machines, called Pascals calculators and later Pascalines.', 0),
(4, 'Daniel Brandur Sigurgeirsson', '1973-01-01', '0000-01-01', 'Male', 'Teaches programming at Reykjavik University. Managed to run whole 10 km in 76:02 minutes. Some say he will be the guy to cure stomach ache permanently. Office workers are not so impressed with him after the release of the disputed program SitStretch that made them move. He is an enthusiastic environmentalist and manages the Icelandic facebook group Ahugahopur um endurvinnslu og endurnytingu, and is a supporter of the English football club Liverpool.', 1),
(5, 'Marissa Ann Mayer', '1975-01-01', '0000-01-01', 'Female', 'Was the first female engineer hired at Google, and was later named Vice President of Search Product and User Experience. She is currently the CEO of Yahoo!', 1),
(6, 'Grace Brewster Murray Hopper', '1906-01-01', '1992-01-01', 'Female', 'Was the first person to create a compiler for a Programming language and one of the first programmers of Mark I computer.', 0),
(7, 'Adele Goldberg', '1945-01-01', '0000-01-01', 'Female', 'She participated in developing the programming language Smalltalk.', 1),
(8, 'Joseph Clement', '1779-01-01', '1844-01-01', 'Male', 'Chiefly remembered as the maker of Charles Babbages first Difference engine, between 1824 and 1833.', 0),
(9, 'Charles Xavier Thomas de Colmar', '1785-01-01', '1870-01-01', 'Male', 'He was a French inventor and entrepreneur best known for designing patenting and manufacturing the first commercially successful mechanical calculator the Arithmometer.', 0),
(10, 'Harry Wimperis', '1876-01-01', '1960-01-01', 'Male', 'He is among other things known for the development of the Drift Sight and Course Setting Bomb Sight during World War I, devices that revolutionized the art of bombing.', 0),
(11, 'Konrad Zuse', '1910-01-01', '1995-01-01', 'Male', 'He was a German civil engineer, inventor and computer pioneer. His greatest achievement was the worlds first programmable computer; the functional program-controlled Turing-complete Z3 became operational in May 1941. Thanks to this machine and its predecessors, Zuse has often been regarded as the inventor of the modern computer.', 0),
(12, 'John Vincent Atanasoff', '1903-01-01', '1995-01-01', 'Male', 'Was an American physicist and inventor, best known for being credited with inventing the first electronic digital computer.', 0),
(13, 'Clifford E. Berry', '1918-01-01', '1963-01-01', 'Male', 'He  helped John Vincent Atanasoff create the first digital electronic computer in 1939, the Atanasoff–Berry computer (ABC).', 0),
(14, 'Tommy Flowers', '1905-01-01', '1998-01-01', 'Male', 'An English engineer. During World War II, Flowers designed Colossus, the worlds first programmable electronic computer, to help solve encrypted German messages.', 0),
(15, 'Allen William Mark Coombs', '1911-01-01', '0000-00-00', '1995-01-01', 'A British electronics engineer at the Post Office Research Station Dollis Hill He was one of the principal designers of the Mark II or production version of the Colossus computer used at Bletchley Park for codebreaking in World War II and took over leadership of the project when Tommy Flowers moved on to other projects.', 0),
(16, 'John Mauchly', '1907-01-01', '1980-01-01', 'Male', 'An American physicist who, along with J. Presper Eckert, designed ENIAC, the first general purpose electronic digital computer, as well as EDVAC, BINAC and UNIVAC I, the first commercial computer made in the United States.', 0),
(17, 'John Adam Presper Eckert, Jr.', '1919-01-01', '1995-01-01', 'Male', 'Was an American electrical engineer and computer pioneer. With John Mauchly he invented the first general-purpose electronic digital computer ENIAC, presented the first course in computing topics the Moore School Lectures, founded the Eckert–Mauchly Computer Corporation, and designed the first commercial computer in the U.S., the UNIVAC, which incorporated Eckerts invention of the mercury delay line memory.', 0),
(18, 'Arthur Scherbius', '1878-01-01', '1929-01-01', 'Male', 'A German electrical engineer who patented an invention for a mechanical cipher machine, later sold as the Enigma machine.', 0),
(19, 'Sir Frederic Calland Williams', '1911-01-01', '1977-01-01', 'Male', 'An English engineer.', 0),
(20, 'Tom Kilburn', '1921-01-01', '2001-01-01', 'Male', 'Was an English mathematician and computer scientist. Over the course of a productive 30-year career, he was involved in the development of five computers of great historical significance.', 0),
(21, 'Geoff Tootill', '1922-01-01', '0000-01-01', 'Male', 'Is a noted computer scientist who worked at the University of Manchester with Frederic Calland Williams and Tom Kilburn developing the worlds first wholly electronic stored program computer.', 1);

-- --------------------------------------------------------

--
-- Table structure for table `computer_scientists_computers`
--

CREATE TABLE `computer_scientists_computers` (
  `ID` int(11) NOT NULL,
  `computer_scientist_ID` int(11) NOT NULL,
  `computer_ID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `type`
--

CREATE TABLE `type` (
  `ID` int(11) NOT NULL,
  `name` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `type`
--

INSERT INTO `type` (`ID`, `name`) VALUES
(1, 'Mechanical calculator'),
(2, 'Mechanical computer'),
(15, 'Mechanical device'),
(16, 'Binary electrically driven mechanical calculator wtih limited programmability'),
(17, 'Electromechanical relay computer'),
(18, 'Electromechanical programmable, fully automatic digital computer'),
(19, 'Electronic digital calculating device'),
(20, 'Electronic digital programmable computer'),
(21, 'Electro-mechanical rotor chipher machine'),
(22, 'Store-program computer');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `computers`
--
ALTER TABLE `computers`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `type_fk_idx` (`type_ID`);

--
-- Indexes for table `computer_scientists`
--
ALTER TABLE `computer_scientists`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `computer_scientists_computers`
--
ALTER TABLE `computer_scientists_computers`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `cmp_scientist_1_idx` (`computer_scientist_ID`),
  ADD KEY `computer_fk_idx` (`computer_ID`);

--
-- Indexes for table `type`
--
ALTER TABLE `type`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `computers`
--
ALTER TABLE `computers`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;
--
-- AUTO_INCREMENT for table `computer_scientists`
--
ALTER TABLE `computer_scientists`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=22;
--
-- AUTO_INCREMENT for table `computer_scientists_computers`
--
ALTER TABLE `computer_scientists_computers`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `type`
--
ALTER TABLE `type`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;
--
-- Constraints for dumped tables
--

--
-- Constraints for table `computers`
--
ALTER TABLE `computers`
  ADD CONSTRAINT `type_fk` FOREIGN KEY (`type_ID`) REFERENCES `type` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `computer_scientists_computers`
--
ALTER TABLE `computer_scientists_computers`
  ADD CONSTRAINT `cmp_scientist_1` FOREIGN KEY (`computer_scientist_ID`) REFERENCES `computer_scientists` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `computer_fk` FOREIGN KEY (`computer_ID`) REFERENCES `computers` (`ID`) ON DELETE NO ACTION ON UPDATE NO ACTION;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
