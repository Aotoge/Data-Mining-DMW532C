# Lab 3
## Clustering Algorithms

![](https://img.shields.io/badge/language-python-blueviolet)

### Contents
* [K-Means Clustering](#a)
* [Partition Around Medoids (PAM) Clustering](#b)
* [Dataset Description](#c)

___

<a name="a"></a>
## K-Means Clustering

Apply K-means algorithm to 'Absenteeism At Work' dataset and find corresponding accuracy and mean squared error in prediction.

To execute:
```
pip3 install -r requirements.txt
python3 kmeans.py
```
___

<a name="b"></a>
## Partition Around Medoids (PAM) Clustering

Apply PAM algorithm to 'Absenteeism At Work' dataset and find corresponding accuracy and mean squared error in prediction.

To execute:
```
pip3 install -r requirements.txt
python3 pam.py
```
___

<a name="c"></a>
## Dataset Description

Number of Attributes: 21

Attribute Information:
* Individual identification (ID)
* Reason for absence ICD. 7 categories without ICD approval are: patient follow-up (22), medical consultation (23), blood donation (24), laboratory examination (25), unjustified absence (26), physiotherapy (27), dental consultation (28). Absences attested by the ICD are stratified into 21 categories (I to XXI) as follows:
  + I Certain infectious and parasitic diseases
  + II Neoplasms
  + III Diseases of the blood and blood-forming organs and certain disorders involving the immune mechanism
  + IV Endocrine, nutritional and metabolic diseases
  + V Mental and behavioural disorders
  + VI Diseases of the nervous system
  + VII Diseases of the eye and adnexa
  + VIII Diseases of the ear and mastoid process
  + IX Diseases of the circulatory system
  + X Diseases of the respiratory system
  + XI Diseases of the digestive system
  + XII Diseases of the skin and subcutaneous tissue
  + XIII Diseases of the musculoskeletal system and connective tissue
  + XIV Diseases of the genitourinary system
  + XV Pregnancy, childbirth and the puerperium
  + XVI Certain conditions originating in the perinatal period
  + XVII Congenital malformations, deformations and chromosomal abnormalities
  + XVIII Symptoms, signs and abnormal clinical and laboratory findings, not elsewhere classified
  + XIX Injury, poisoning and certain other consequences of external causes
  + XX External causes of morbidity and mortality
  + XXI Factors influencing health status and contact with health services.
* Month of absence
* Day of the week (Monday (2), Tuesday (3), Wednesday (4), Thursday (5), Friday (6))
* Seasons (summer (1), autumn (2), winter (3), spring (4))
* Transportation expense
* Distance from Residence to Work (kilometers)
* Service time
* Age
* Work load Average/day
* Hit target
* Disciplinary failure (yes=1; no=0)
* Education (high school (1), graduate (2), postgraduate (3), master and doctor (4))
* Son (number of children)
* Social drinker (yes=1; no=0)
* Social smoker (yes=1; no=0)
* Pet (number of pet)
* Weight
* Height
* Body mass index
* Absenteeism time in hours (target) 