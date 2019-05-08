#!/usr/bin/env python
# -*- coding: utf-8 -*-
import numpy as np
from PyQt5.QtWidgets import *
'''工具类的函数写在这里，如坐标系转换函数'''
def Flip_180(arr):
    '''数组反转'''
    new_arr = arr.reshape(arr.size)
    new_arr = new_arr[::-1]
    new_arr = new_arr.reshape(arr.shape)
    return new_arr

