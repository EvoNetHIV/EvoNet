EvoNetHIV User Guide
================
January 2018

------------------------------------------------------------------------

A software package for modeling HIV epidemics and viral evolution in sexual networks

------------------------------------------------------------------------

Preface
-------

This document describes an R package, EvoNetHIV, that allows users to model the interactions between social networks and the evolution and epidemiology of HIV. The package is being developed and used by a research team at the University of Washington (Seattle, WA, USA).

Interaction with other packages
-------------------------------

The package uses the API (application programming interface) of the R package **EpiModel** (<http://www.epimodel.org/>), so familiarity with that API and package is helpful. We provide an introduction below, as well as links to more information for advanced users. Users who wish to model new network structures will also need to be familiar with the methods and syntax from the **statnet** suite of R packages (<http://www.statnet.org/>). We also provide a brief overview, and links for more information, within this guide. For updates and further information about this package, please visit <https://github.com/EvoNetHIV>.

Funding
-------

This project is supported by grants from the National Institutes of Health (NIAD R01AI108490 and NIGMS R01GM125440 (via [MIDAS](https://www.nigms.nih.gov/Research/specificareas/MIDAS/Pages/default.aspx))) and the Center for Demography and Ecology at the University of Washington (<https://csde.washington.edu/>).

Authors
-------

-   James T. Murphy <jtm6@uw.edu>
-   John E. Mittler <jmittler@uw.edu>
-   Steven M. Goodreau <goodreau@uw.edu>
-   Joshua T. Herbeck <herbeck@uw.edu>
-   Kathryn Peebles <kpeebles@uw.edu>
-   Sarah E. Stansfield <sestan@uw.edu>

Neil Abernethy, Juandalyn Burke, and Geoff Gottlieb have also made contributions to model development.

------------------------------------------------------------------------

Table of contents
-----------------

[General model overview](https://github.com/EvoNetHIV/EvoNet/blob/master/documentation/EvoNetHIV%20Users%20Guide.Rmd#General-model-overview) [Structure](https://github.com/EvoNetHIV/EvoNet/blob/master/documentation/EvoNetHIV%20Users%20Guide.Rmd#Structure) [How to use](https://github.com/EvoNetHIV/EvoNet/blob/master/documentation/EvoNetHIV%20Users%20Guide.Rmd#How-to-use-the-model)

General model overview
----------------------

EvoNetHIV is an HIV epidemic simulation model that incorporates sexual network structure, within-host viral and immune system dynamics, antiretroviral therapy, vaccination, condom use, circumcision, demography, and viral evolution.

EvoNetHIV is an agent-based simulation model. Each agent (i.e., individual) is a discrete entity that has over 30 attributes. Important agent attributes include sex, age, HIV infection status, time of infection, viral load, set-point viral load, antiretroviral treatment status, and vaccination status. Some attributes are regularly updated, such as age or viral load (for infected agents) while others (e.g. sex, set-point viral load), do not change once assigned to the agent. Agents are “born” (added to the model as uninfected individuals), age, and depart from the model, either through death from AIDS, death from background mortality, or aging out. Agents can become infected and infect other agents. Agents cannot be infected twice (experience dual or super-infection).

EvoNetHIV is a stochastic model, such that identical parameter values or starting conditions for different model runs will produce different results. Many input parameters are mean or variance values of probability distributions used to draw random numbers from the specified probability distribution. For example, the parameter for mean sex acts per ongoing relationship per time step is the mean value for a draw from a Poisson distribution. Model dynamics occur on a daily timestep; thus fine-scale epidemiological and behavioral processes can be simulated.

### Structure

EvoNetHIV is written in the R programming language as a series of interchangeable modules and user-specified parameter values that control different components of the system (e.g. network structure; sexual behavior; within-host dynamics (viral load, disease progression), and treatment or other public health interventions). As noted, above, EvoNetHIV uses a modular framework from the [EpiModel](http://www.epimodel.org/) API.

**Network structure**
Agents can be either isolates or have one or more concurrent relationships with other agents. This network structure is dynamic and changes according to the specified network statistics. The network module is built using exponential random graph models in the [statnet](http://www.statnet.org/) framework, which provides a language for specifying arbitrarily complex network models.

**Sexual behavior**
Important behavioral dynamics include sex roles (for MSM), frequency of sex, condom use, HIV testing frequency, and adherence to treatment. Behavioral dynamics can be specified by the user.

-   *MSM model*. Each agent is assigned either an *insertive*, *receptive*, or *versatile* role. Insertive agents can form relationships with versatile or receptive agents; receptive agents can form relationships with versatile or insertive agents; and versatile agents can form relationships with all three agent types. Under our default parameters, receptive agents have a higher per-act probability of getting infected.

-   *Heterosexual model*. Only relationships between opposite sexes are allowed. Under our default parameters, the population tends to a 50-50 sex ratio. Although our default parameters assume that men and women are equally susceptible, parameters governing the relative suspectibility of men and women can be changed.

**Within-host dynamics**

-   *Set point viral load (SPVL)*. The viral load at the beginning of the chronic phase of infection is referred to as set-point viral load (SPVL). SPVL is partially heritable across transmission pairs: SPVL for newly infected agents is determined by a combination of the donor’s SPVL and by environmental (random) variation. The contribution of the donor’s SPVL to the recipient’s SPVL is determined by the assumed (user-defined) heritability of HIV SPVL.

-   *Viral load progression*. The model divides infection into three phases: an acute phase when viral load rises and declines rapidly; a chronic phase when viral load increases slowly over a periodc of years; and AIDS phase when viral load increases rapidly to a high AIDS-specific viral load.

-   *CD4+ T cell dynamics*. The model follows CD4 dynamics in HIV infection as described in Cori et al (2015). In the absence of antiretroviral treatment, the model relates individual SPVL to the starting CD4 count category (individual CD4 count immediately after infection) and to disease progression based on waiting times in four CD4 count categories: CD4≥500; 500&gt;CD4≥350; 350&gt;CD4≥200; CD4&lt;200 (AIDS).

**Public health actions**

-   *Antiretroviral treatment (ART)*. ART is provided to HIV-infected individuals based on user-defined categories of eligibility. Eligibility can be determined by CD4 count or by time elapsed since infection. Viral load after ART initiation drops to 50 copies/mL.

-   *Vaccination*. Currently, the HIV vaccine in the model is protective, not therapeutic: it protects vaccinated individuals from infection by decreasing the per-act rate of transmission, but does not affect disease progression or the viral load of a vaccinated individual if that person becomes infected. The model also includes viral diversity with respect to vaccination, via one locus with two alleles: sensitive and resistant. Sensitive viruses have reduced per-contact probabilities of infecting vaccinated hosts, determined by the user-defined vaccine efficacy. Resistant viruses experience no change in infection probability, regardless of the vaccination status of possible recipients. The duration of vaccine effect is also a user-defined parameter.

### Model processes

In this section we give an overview of the assumptions made by our default modules. Additional details and descriptions of alternative (nondefault) modules are given in the programming guide in Section 2.

#### Behavior

-   *Network structure and dynamics*. User-defined network parameters can be implemented (e.g., mean degree, age and other subgroup structure) based on the statnet and EpiModel packages. The default structure is random mixing of agents with a network mean degree of 0.7. Each agent can exist as an isolate (no partners) or have one or more sexual partners per timestep. The default mean partnership duration is 100 days.

-   *Sex*. Sexual acts (coital acts) are determined among agents in a serodiscordant relationship at each daily time step. Among these partnerships, the number of sexual acts per partnership per daily time step is assigned according to a Poisson draw (mean = 0.43). Probability of sex can also be a declining function of age. Default condom use is determined for each sexual act with probability of 50% and default circumcision status is assigned to agents at model entry with 85% probability. When the infected partner is 47% past their expected time in AIDS, no sex occurs. For MSM models, agents are assigned one of three sexual roles: versatile, insertive, and receptive. Insertive agents only have sex with receptive agents and vice-versa. Versatile agents can have sex with any other agents. Intra-event versatility (when men switch roles and each engage in insertive and receptive anal intercourse (AI) during the same sexual contact) occurs with 40% probability when both partners are role versatile.

#### Viral load

-   *Set point viral load*. At infection, agents are assigned a set point viral load (SPVL), using a function that incorporates infector SPVL, assumed heritability of SPVL, and a randomly determined host-specific factor (stochastic white noise), and heritability. The maximum possible viral load (all viral dynamics on log10 scale) is 7.0 and the minimum is 2.0.

-   *Daily viral load*. Initial VL starts out at -4.0 rises exponentially to a peak acute phase level, and then has a biphasic decay to SPVL. The acute phase last 50 days. Default value for peak acute phase VL is constant for all agents but can be set to be a function of an agent’s SPVL. After the end of the acute phase, VL increases linearly, starting at SPVL, at a pre-specified chronic phase rate of increase. At the onset of AIDS, VL increases linearly at a pre-specified rate of increase for the AIDS phase until it reaches the assumed maximum VL value for AIDS at which it remains until agent’s death. (The onset of AIDS is triggered by CD4 values.) With commencement of ART, VL will decrease linearly over 30 days to a “undetectable” level of 1.7 and remain there for the duration of treatment. If treatment stops, VL will then increase linearly over 30 days to the VL level at the start of treatment and then progress as if treatment did not occur.

#### CD4 dynamics

-   CD4 counts for individuals are recorded as ordinal variables with four categories; categories 1, 2, 3, and 4 represent CD4&gt;500, 500&gt;CD4&gt;350, 350&gt;CD4&gt;200, 200&gt;CD4&gt;0, respectively. Category 4 also represents the AIDS stage.

-   At infection, an individual is probabilistically assigned an initial CD4 category (1, 2, or 3) where higher SPVL values increases the probability of assignment to categories 2 or 3. (Table 1). For each daily timestep, an infected agent in categories 1, 2, or 3 can move to the following CD4 category (representing lower CD4 counts) or remain in the current category based on the outcome of a Bernoulli trial with the probability of success (moving to the next category) equal to the inverse of the mean passage time (in days) for a given SPVL and CD4 category (Table 2). Duration in CD4 category 4 is fixed for each SPVL category; at the end of time in category 4, an individuals is categorized as having died of AIDS.

-   With commencement of ART, an individuals’s CD4 category is set to 1 and remains there until treatment stops or death. If treatment stops before death, the CD4 category is set equal to the value at the start of treatment.

#### HIV transmission

HIV transmission probabilities are calculated as a function of relevant risk factors for each sex act according to characteristics of the sexual act and characteristics of the agents engaged in the sexual act. Following Hughes et al (2012), the probability of transmission is calculated for each sexual act that occurs in a serodiscordant relationship, as:

*P*(*t**r**a**n**s**m**i**s**s**i**o**n*)=1 − (1 − *λ*)<sup>*e**X**β*</sup>

where λ is the baseline per-act infectivity (0.000247).

We have different transmission probabilities for heterosexual and MSM partners. For heterosexual partners,

*X**β* = *l**n*(2.89 \* (*V**L* − 4.0)+*l**n*(*R**R*<sub>*c**i**r**c**u**m**c**i**s**e**d*</sub>)\**c**i**r**c**u**m**c**i**s**e**d* + *l**n*(*R**R*<sub>*c**o**n**d**o**m*</sub>)\**c**o**n**d**o**m* + *l**n*(*R**R*<sub>*a**g**e*</sub>)\**a**g**e*<sub>*b**a**s**e*</sub> + *l**n*(*R**R*<sub>*S**T**I*</sub>)\**S**T**I*.*s**t**a**t**u**s*.*s**u**s*

where circumcised is an indicator variable for the circumcision status of the male, STI (sexually transmitted infection) is an indicator variable for any STI, condom is an indicator variable for condom use for the male, VL is the log10 viral load of infected agent, and age\_base is the number of decades over 35 the susceptible agent is: (age-35)/10; and RR\_x is the risk factor.

For MSM partners,

*X**β* = *l**n*(*R**R*<sub>*V*</sub>*L*)\*(*V**L* − 4.0)+*l**n*(*R**R*<sub>*i**n**s**e**r**t**i**v**e*</sub>)\**i**n**s**e**r**t**i**v**e* + *l**n*(*R**R*<sub>*r**e**c**e**p**t**i**v**e*</sub>)\**r**e**c**e**p**t**i**v**e* + *l**n*(*R**R*<sub>*c**i**r**c**u**m**c**i**s**e**d*</sub>)) \* *c**i**r**c**u**m**c**i**s**e**d* + *l**n*(*R**R*<sub>*c**o**n**d**o**m*</sub>)\**c**o**n**d**o**m* + *l**n*(*R**R*<sub>*s**t**i*</sub>)\**s**t**i*.*s**t**a**t**u**s*.*s**u**s*

where insertive and receptive are indicator variables for role of susceptible agent and other variables are as for heterosexual partners.

Once the probability of transmission is calculated, a random uniform draw determines whether infection occurred.

#### Demographics

The model allows users to specific an initial age distribution. The model accounts for births, natural mortality, death due to AIDS, and the potential for agents to age out of the sexually active population. Each agent ages 1/365 of a year each day. Depending on parameter choices, variety of age distributions, including (approximately) stable age distributions, can be achieved.

How to use the model
--------------------

Users may interact with EvoNetHIV in one of four principal ways to conduct their own experiments: a) they may keep the model structure exactly as is, but vary some of the many dozen input parameters; b) they may use some of the alternative functional forms included with the model through the use of flag arguments; c) they may keep the model structure as is, but vary the network model and associated parameters through the use of *ergm* terms; d) they may change the structure of the model through the writing of substitute modules. Each of these features requires understanding the current model, and being familiar with the default parameter values; these are described below.

Option *c* requires familiarity with the mathematics and terminology of exponential random graph models, and option *d* requires familiarity with the EpiModel API; an introduction to each of these can be found here: <http://statnet.github.io/nme/>

Advanced users have the option of creating new functions or variants of existing functions (described in more detail below). e.g. Someone wanting to specify that “versatile” men are more likely to use condoms, for example, could write a variant of our condom usage function that does this.
