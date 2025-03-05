 
linkSegmentsWithJoints = createLineSegmentsWithJoints(mdhparams,robot,[0.1,0.1,0.07,0.08,0.07,0,0.08],[0.1,0.1,0.06,0.04,0.05,0,0.08],Homejointpositions);

avo = linkSegmentsWithJoints(5).aSegmentV0;
av1 = linkSegmentsWithJoints(5).aSegmentV0;
dv0 = linkSegmentsWithJoints(5).dSegmentV0;
dv1 = linkSegmentsWithJoints(5).dSegmentV1;
radiusLink = linkSegmentsWithJoints(5).radius;
radiusJoint = linkSegmentsWithJoints(5).radiusJoint;



plotLinksModeling(linkSegmentsWithJoints);
show(frankarobot,Initalconfig,'Frames','off','PreservePlot',true);
hold on;
plotBox([0.5545,0,0.5695],[0.06,0.2,0.11],[0,1,0,0]);
zlim([-0.1 0.9])
ylim([-0.3 0.3])
xlim([-0.5 1])
