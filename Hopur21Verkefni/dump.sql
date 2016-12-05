SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

CREATE SCHEMA IF NOT EXISTS `harlausniris_computer_scientist` DEFAULT CHARACTER SET utf8 ;
USE `harlausniris_computer_scientist` ;

CREATE TABLE IF NOT EXISTS `harlausniris_computer_scientist`.`type` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;

CREATE TABLE IF NOT EXISTS `harlausniris_computer_scientist`.`computers` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(255) NOT NULL,
  `design_year` DATE NULL,
  `build_year` DATE NULL DEFAULT NULL,
  `type_ID` INT(11) NOT NULL,
  `is_created` TINYINT(1) NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `type_fk_idx` (`type_ID` ASC),
  CONSTRAINT `type_fk`
    FOREIGN KEY (`type_ID`)
    REFERENCES `harlausniris_computer_scientist`.`type` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;

CREATE TABLE IF NOT EXISTS `harlausniris_computer_scientist`.`computer_scientists` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(255) NOT NULL,
  `birth_year` DATE NOT NULL,
  `death_year` DATE NOT NULL,
  `gender` VARCHAR(255) NOT NULL,
  `comment` VARCHAR(10000) NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;

CREATE TABLE IF NOT EXISTS `harlausniris_computer_scientist`.`computer_scientists_computers` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `computer_scientist_ID` INT(11) NOT NULL,
  `computer_ID` INT(11) NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `cmp_scientist_1_idx` (`computer_scientist_ID` ASC),
  INDEX `computer_fk_idx` (`computer_ID` ASC),
  CONSTRAINT `cmp_scientist_1`
    FOREIGN KEY (`computer_scientist_ID`)
    REFERENCES `harlausniris_computer_scientist`.`computer_scientists` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `computer_fk`
    FOREIGN KEY (`computer_ID`)
    REFERENCES `harlausniris_computer_scientist`.`computers` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
