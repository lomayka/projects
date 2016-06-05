import psycopg2
import sys

class DB_Handler:
    def __init__(self, name):
        self.con = None
        self.name = name

    def connect(self):
        try:
            self.con = psycopg2.connect(database=self.name, user='postgres', password='1234', port='8888')
        except psycopg2.DatabaseError, e:
            print 'Error %s' % e
            sys.exit(1)

    def getTablesName(self):
        cur = self.con.cursor()
        cur.execute("select table_name from information_schema.tables where table_schema='public'")
        rows = cur.fetchall();
        i = 0
        for row in rows:
            rows[i] = str(row)[2:len(row)-4]
            i +=1
        return rows

    def getTableColums(self,table_name):
            cur = self.con.cursor()
            messege = "SELECT column_name FROM information_schema.columns WHERE table_name   = '%s'" % (table_name)
            cur.execute(messege)
            rows = cur.fetchall();
            i = 0
            for row in rows:
                rows[i] = str(row)[2:len(row) - 4]
                i += 1
            return rows

    def getTableColumsType(self, table_name):
        cur = self.con.cursor()
        messege = "SELECT data_type FROM information_schema.columns WHERE table_name   = '%s'" % (table_name)
        cur.execute(messege)
        rows = cur.fetchall();
        i = 0
        for row in rows:
            rows[i] = str(row)[2:len(row) - 4]
            i += 1
        return rows
    def getTablesCount(self):
        cur = self.con.cursor()
        cur.execute("SELECT count(*) from information_schema.tables where table_schema = 'public';")
        row = cur.fetchall();
        row = str(row)[2:len(row) - 4]
        return long(row)
    def getTableContent(self,table_name):
        cur = self.con.cursor()
        messege = "SELECT * FROM %s ;" % (table_name)
        cur.execute(messege)
        rows = cur.fetchall();
        return rows
    def getColumnsCount(self,table_name):
        cur = self.con.cursor()
        messege = "SELECT COUNT(column) FROM  %s ;" % (table_name)
        cur.execute(messege);
        row = cur.fetchall();
        row = str(row)[2:len(row) - 4]
        return long(row)
    def insert(self,messege):
        try:
            cur = self.con.cursor()
            cur.execute(messege)
            self.con.commit()
            if self.con:
                self.con.close()
            return 1
        except psycopg2.DatabaseError, e:
            if self.con:
                self.con.rollback()
                self.con.close()
                return 0








