#!/usr/bin/python3
# -*- coding: utf-8 -*-

import smtplib
from email.mime.text import MIMEText
from email.mime.application import MIMEApplication
from email.mime.multipart import MIMEMultipart

from os.path import basename

import csv
import textwrap

from getpass import getpass

class Person(object):
    def __init__(self, row):
        self.name = row[0]
        self.mail = row[1]

    def mailbody(self):
        # メール雛形
        body = textwrap.dedent('''\
            ##TO_NAME## 様

            3月も半ばを過ぎ、次第に春めいてまいりました。

            本日はpythonからテストメールを送信してみましたが、
            皆様におかれましてはいかがお過ごしでしょうか。
            ''')

        # ##で挟まれた文字列を置換して個別のメールにする
        body = body.replace("##TO_NAME##", self.name)
        print(str(body))

        return body


def get_sender_account():
    with open('mailaccount.txt') as f:
        lines = f.readlines()

    myaddr = lines[0].split(":")[1].rstrip()

    mypass = getpass('gmailパスワードを入力してください: ')

    return myaddr, mypass


def send_mail(myaddr="",
              mypass="",
              from_addr="",
              to_addrs=[],
              cc_addrs=[],
              bcc_addrs=[],
              subject="default_subject",
              mailbody="default mailbody"):

    msg = MIMEMultipart()

    # メール本体を作成する
    msg["Subject"] = subject
    msg["From"] = from_addr
    msg["To"] = ",".join(to_addrs)
    print(msg["To"])

    if cc_addrs != []:
        msg["Cc"] = ",".join(cc_addrs)
    if bcc_addrs != []:
        msg["Bcc"] = ",".join(bcc_addrs)
    msg.attach(MIMEText(mailbody))

    # ファイルを添付する
    attach_filename = 'attach.pdf'
    with open(attach_filename, 'rb') as f:
        attach_file = MIMEApplication(f.read(), _subtype="pdf")

    attach_file.add_header('Content-Disposition',
                           'attachment', filename=attach_filename)

    msg.attach(attach_file)

    # 送信する
    smtp = smtplib.SMTP("smtp.gmail.com", 587)
    smtp.ehlo()
    smtp.starttls()
    smtp.login(myaddr, mypass)
    smtp.send_message(msg)
    smtp.close()


def main():

    # メール送信者のgmailアカウント情報を読み取る
    myaddr, mypass = get_sender_account()

    # 送付先のリストをcsvファイルから読み取る
    with open('sendlist.csv', 'r') as f:
        csvlist = list(csv.reader(f))

        # リストの2行目以降に個別にメールを送付する
        for row in csvlist[1:]:
            person = Person(row)

            # 送付先とメール本文を指定してメールを送る
            # デフォルトではccに送信元のメールアドレスが設定されます。
            send_mail(myaddr=myaddr,
                      mypass=mypass,
                      from_addr=myaddr,
                      to_addrs=[person.mail],
                      cc_addrs=[myaddr],
                      bcc_addrs=[],
                      subject="これはpythonによるメール自動送信テストです",
                      mailbody=person.mailbody())


if __name__ == '__main__':

    main()