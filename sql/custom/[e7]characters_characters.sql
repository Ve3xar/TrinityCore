ALTER TABLE `characters`
    ADD COLUMN `gloryPoints` INT(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `deleteDate`;