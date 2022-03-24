CREATE TYPE S_tbl AS ("time" integer, "#t" integer, "op" character, "attr" character);
CREATE TABLE "Schedule"       OF S_tbl (PRIMARY KEY(time));