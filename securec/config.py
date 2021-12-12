import os

cwpath = None
firmwarepath = None
for cwpath in (os.path.join(os.path.dirname(__file__), p) for p in (
    '../..',
    '../../chipwhisperer',
    '../../../chipwhisperer',
)):
    firmwarepath = os.path.abspath(os.path.join(cwpath, 'hardware/victims/firmware'))
    if os.path.exists(firmwarepath):
        break

if not os.path.exists(firmwarepath):
    raise ValueError('FIRMWAREPATH not found')